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
#define MAX 100001
typedef long long ll;
using namespace std;

void init();
void solve();
void topologySort();

int n,m;
int inDegree[MAX];
int result[MAX];
bool flag;
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
        int k,s,e;
        cin>>k;
        cin>>s;
        for(int j=0;j<k-1;j++){
            cin>>e;
            a[s].push_back(e);
            inDegree[e]++;
            s=e;
        }
    }
}

void solve(){
    topologySort();
    if(flag){
        cout<<"0\n";
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<result[i]<<"\n";
        }
    }
}

void topologySort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0) q.push(i);
    }
    for(int i=1;i<=n;i++){
        if(q.empty()){
            flag=true;
            return;
        }
        int x=q.front();
        q.pop();
        result[i]=x;
        for(int j=0;j<a[x].size();j++){
            int y=a[x][j];
            if(--inDegree[y]==0) q.push(y);
        }
    }
}