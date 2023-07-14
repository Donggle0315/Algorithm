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
bool cmp(pair<pii,int>, pair<pii,int>);
int find(int);
bool UNION(int,int);
int kruskal();
 
int vertex,edge;
int parent[10001];
int height[10001];
vector<pair<pii,int> > vec;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<kruskal()<<"\n";

    return 0;
}

void init(){
    cin>>vertex>>edge;
    memset(&parent,-1,sizeof(parent));
    for(int i=1;i<=edge;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vec.push_back(make_pair(make_pair(a,b),c));
    }
    sort(vec.begin(),vec.end(),cmp);
}

bool cmp(pair<pii, int> v1, pair<pii, int> v2){
    if(v1.second==v2.second){
        if(v1.first.first==v2.first.first){
            return v1.first.second<v2.first.second;
        }
        return v1.first.first<v2.first.first;
    }
    return v1.second<v2.second;
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

int kruskal(){
    int weight=0;

    for(int i=0;i<edge;i++){
        if(UNION(vec[i].first.first,vec[i].first.second)){
            weight+=vec[i].second;
        }
    }
    return weight;
}