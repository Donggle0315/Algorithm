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
void canTravel();

int n,m;
vector<int> vec;
int parent[201];
int height[201];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            cin>>tmp;
            if(tmp==1){
                UNION(i,j);
            }
        }
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    canTravel();
    
    return 0;
}

void canTravel(){
    for(int i=0;i<m-1;i++){
        if(find(vec[i])!=find(vec[i+1])){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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