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
void solve();
void palin();

int n,m;
vector<int> vec;
bool dp[2001][2001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    palin();
    solve();

    return 0;
}

void init(){
    cin>>n;
    vec.push_back(0);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    cin>>m;
}

void solve(){
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(dp[a][b]) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}

void palin(){
    for(int i=1;i<=n;i++){
        dp[i][i]=true;
    }
    for(int i=1;i<=n-1;i++){
        if(vec[i]==vec[i+1]) dp[i][i+1]=true;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+2;j<=n;j++){
            if(vec[i]==vec[j]&&dp[i+1][j-1]) dp[i][j]=true;
        }
    }
}