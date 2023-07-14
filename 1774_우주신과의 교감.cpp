#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#define pii pair<int,int>
#define INF 1e9+7
#define MOD 1004
typedef long long ll;
using namespace std;

void init();
int find(int);
bool UNION(int,int);
double findmst();
void getDist();
double calDist(ll,ll,ll,ll);
bool cmp(pair<pair<ll,ll>,double>,pair<pair<ll,ll>,double>);

int n,m;
int list[1001][1001];
ll pos[1001][2];
vector<pair<pair<ll,ll>,double> > dist;
int parent[1001];
int height[1001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    getDist();
    sort(dist.begin(),dist.end(),cmp);
    cout<<fixed;
    cout.precision(2);
    cout<<findmst()<<"\n";


    return 0;
}

void init(){
    cin>>n>>m;
    memset(&parent,-1,sizeof(parent));
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        pos[i][0]=x;
        pos[i][1]=y;
    }
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        list[x][y]=1;
        list[y][x]=1;
        UNION(x,y);
    }
}

void getDist(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(list[i][j]==1) continue;
            double length=calDist(pos[i][0],pos[j][0],pos[i][1],pos[j][1]);
            dist.push_back(make_pair(make_pair(i,j),length));

        }
    }
}

double calDist(ll x1,ll x2,ll y1,ll y2){
    double ans=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return ans;
}

bool cmp(pair<pair<ll,ll>,double> v1, pair<pair<ll,ll>,double> v2){
    if(v1.second==v2.second){
        if(v1.first.first==v2.first.second){
            return v1.first.second<v2.first.second;
        }
        return v1.first.first<v2.first.first;
    }
    return v1.second<v2.second;
}

double findmst(){
    double weight=0;
    for(int i=0;i<dist.size();i++){
        if(UNION(dist[i].first.first,dist[i].first.second)) {
            weight+=(dist[i].second);
        }
    }
    return weight;
}

int find(int x){
    if(parent[x]==-1) return x;
    return parent[x]=find(parent[x]);
}

bool UNION(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y) return false;
    if(height[x]<height[y]) swap(x,y);
    parent[y]=x;
    if(height[x]==height[y]) height[y]++;
    return true;
}