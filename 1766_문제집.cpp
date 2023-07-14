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
#define MAX 32001
typedef long long ll;
using namespace std;

void init();
void solve();
void topologySort();

int n,m;
int inDegree[MAX];
vector<int> a[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    solve();

    return 0;
}

void init(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        a[s].push_back(e);
        inDegree[e]++;
    }
}

void solve(){
    topologySort();
   
}

void topologySort(){
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0) q.push(-i);
    }
    while(!q.empty()){
        int x=-q.top();
        q.pop();
        cout<<x<<" ";
        for(int j=0;j<a[x].size();j++){
            int y=a[x][j];
            if(--inDegree[y]==0) q.push(-y);
        }
    }
    cout<<"\n";
}