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
#define MAX 501
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
    
    init();
    solve();

    return 0;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>costBuild[i];
        while(true){
            int tmp;
            cin>>tmp;
            if(tmp==-1) break;
            a[tmp].push_back(i);
            inDegree[i]++;
        }
    }
}

void solve(){
    topologySort();
    for(int i=1;i<=n;i++){
        cout<<result[i]<<"\n";
    }
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
}