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
bool cmp(pair<pii,double>, pair<pii,double>);
int find(int);
bool UNION(int,int);
double kruskal();
double getDist(int,int);
 
int n;
int parent[10001];
int height[10001];
vector<pair<double,double> > pos;
vector<pair<pii,double> > dist;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout.precision(3);
    cout<<kruskal()<<"\n";

    return 0;
}

void init(){
    cin>>n;
    memset(&parent,-1,sizeof(parent));
    for(int i=0;i<n;i++){
        double a,b;
        cin>>a>>b;
        pos.push_back(make_pair(a,b));
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double tmp=getDist(i,j);
            dist.push_back(make_pair(make_pair(i,j),tmp));
        }
    }
    sort(dist.begin(),dist.end(),cmp);
}

double getDist(int a, int b){
    double da=(pos[a].first-pos[b].first)*(pos[a].first-pos[b].first);
    double db=(pos[a].second-pos[b].second)*(pos[a].second-pos[b].second);
    return sqrt(da+db);

}

bool cmp(pair<pii, double> v1, pair<pii, double> v2){
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

double kruskal(){
    double weight=0;

    for(int i=0;i<dist.size();i++){
        if(UNION(dist[i].first.first,dist[i].first.second)){
            weight+=dist[i].second;
        }
    }
    return weight;
}