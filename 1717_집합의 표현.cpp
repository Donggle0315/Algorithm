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
 
int n,m;
int parent[1000001];
int height[1000001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0) UNION(b,c);
        else if(find(b)==find(c))cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}

void init(){
    cin>>n>>m;
    memset(&parent,-1,sizeof(parent));
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