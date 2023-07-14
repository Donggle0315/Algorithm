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
int getAns();

int n,m;
int parent[500000];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<getAns()<<"\n";

    return 0;
}

void init(){
    cin>>n>>m;
    memset(&parent,-1,sizeof(parent));
}

int find(int x){
    if(parent[x]==-1) return x;
    return find(parent[x]);
}

bool UNION(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y) return false;
    parent[y]=x;
    return true;
}

int getAns(){
    bool flag;
    int ans=0;
    for(int i=0;i<m;i++){
        bool flag;
        int a,b;
        cin>>a>>b;
        if(!UNION(a,b)){
            ans=i+1;
            break;
        }
    }
    return ans;
}