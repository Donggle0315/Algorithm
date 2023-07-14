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
void solve();
int find(int);
bool UNION(int,int);

int n;
vector<pair<int,pii> > dist;
vector<pii> xpos;
vector<pii> ypos;
vector<pii> zpos;
int parent[100001];
int height[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    solve();

    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        xpos.push_back(make_pair(x,i));
        ypos.push_back(make_pair(y,i));
        zpos.push_back(make_pair(z,i));
    }
    memset(&parent,-1,sizeof(parent));
}

void solve(){
    int ans=0;
    sort(xpos.begin(),xpos.end());
    sort(ypos.begin(),ypos.end());
    sort(zpos.begin(),zpos.end());

    for(int i=0;i<n-1;i++){
        dist.push_back(make_pair(abs(xpos[i].first-xpos[i+1].first),make_pair(xpos[i].second,xpos[i+1].second)));
        dist.push_back(make_pair(abs(ypos[i].first-ypos[i+1].first),make_pair(ypos[i].second,ypos[i+1].second)));
        dist.push_back(make_pair(abs(zpos[i].first-zpos[i+1].first),make_pair(zpos[i].second,zpos[i+1].second)));
    }
    sort(dist.begin(),dist.end());

    for(int i=0;i<dist.size();i++){
        if(UNION(dist[i].second.first,dist[i].second.second)){
            ans+=dist[i].first;
        }
    }
    cout<<ans<<"\n";
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
