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
int findmst();
bool cmp(pair<pii,int>,pair<pii,int>);

int n,m;
vector<pair<pii,int> > vec;
int parent[200001];
int height[200001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    while(1){
        int cost=0;
        vec.clear();
        memset(&parent,-1,sizeof(parent));
        memset(&height,-1,sizeof(parent));
        cin>>m>>n;
        if(m==0&&n==0) break;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            cost+=z;
            vec.push_back(make_pair(make_pair(x,y),z));
        }
        sort(vec.begin(),vec.end(),cmp);
        cost-=findmst();
        cout<<cost<<"\n";
    }
    return 0;
}

bool cmp(pair<pii,int> v1, pair<pii,int> v2){
    if(v1.second==v2.second){
        if(v1.first.first==v2.first.second){
            return v1.first.second<v2.first.second;
        }
        return v1.first.first<v2.first.first;
    }
    return v1.second<v2.second;
}

int findmst(){
    int weight=0;
    for(int i=0;i<vec.size();i++){
        if(UNION(vec[i].first.first,vec[i].first.second)) weight+=vec[i].second;
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