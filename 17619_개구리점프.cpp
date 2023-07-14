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
void makeUnion();
void getDist();
 
int n,q;
vector<pair<pii,int> > vec;
int parent[100002];
int height[100002];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    makeUnion();
    getDist();
    
    return 0;
}

void init(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x1,x2,y;
        cin>>x1>>x2>>y;
        vec.push_back(make_pair(make_pair(x1,x2),i));
    }
    memset(&parent,-1,sizeof(parent));
    sort(vec.begin(),vec.end(),cmp);   
}

void makeUnion(){
    for(int i=0,j=1;i<n&&j<n;){
        if(vec[j].first.first<=vec[i].first.second){
            UNION(vec[i].second,vec[j].second);
            j++;
        }
        else{
            i++;
        }
    }
}

bool cmp(pair<pii,int> v1,pair<pii,int> v2){
    if(v1.first.first==v2.first.first){
        if(v1.first.second==v2.first.second){
            return v1.second<v2.second;
        }
        return v1.first.second<v2.first.second;
    }
    return v1.first.first<v2.first.first;
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

void getDist(){
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }
}