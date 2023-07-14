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
#define MAX 1001
typedef long long ll;
using namespace std;

void init();
void solve();
void topologySort();

int n,k,w;
int inDegree[MAX];
int result[MAX];
int costBuild[MAX];
vector<int> a[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin>>tc;
    while(tc--){
        init();
        solve();
    }

    return 0;
}

void init(){
    memset(&inDegree,0,sizeof(inDegree));
    memset(&result,0,sizeof(result));
    memset(&costBuild,0,sizeof(costBuild));
    for(int i=0;i<MAX;i++){
        a[i].clear();
    }
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>costBuild[i];
    }
    for(int i=0;i<k;i++){
        int s,e;
        cin>>s>>e;
        a[s].push_back(e);
        inDegree[e]++;
    }
    cin>>w;
}

void solve(){
    topologySort();
}

void topologySort(){
    queue<pii> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0) q.push(make_pair(i,costBuild[i]));
    }
    for(int i=1;i<=n;i++){
        if(q.empty()) return;
        int x=q.front().first;
        int cost=q.front().second;
        q.pop();
        result[x]=cost;
        for(int j=0;j<a[x].size();j++){
            int y=a[x][j];
            result[y]=max(result[y],result[x]+costBuild[y]);
            if(--inDegree[y]==0) q.push(make_pair(y,result[y]));
        }
    }
    cout<<result[w]<<"\n";
}