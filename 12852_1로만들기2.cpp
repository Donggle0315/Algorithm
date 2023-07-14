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
void printAns();

int n;
int dp[1000001][2];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    solve();
    printAns();

    return 0;
}

void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i][0]=INF;
        dp[i][1]=0;
    }
    dp[1][0]=0;
}

void solve(){
    for(int i=1;i<n;i++){
        if(i*3<=n&&dp[i][0]+1<dp[i*3][0]){
            dp[i*3][0]=dp[i][0]+1;
            dp[i*3][1]=1;
        }
        if(i*2<=n&&dp[i][0]+1<dp[i*2][0]){
            dp[i*2][0]=dp[i][0]+1;
            dp[i*2][1]=2;
        }
        if(i+1<=n&&dp[i][0]+1<dp[i+1][0]){
            dp[i+1][0]=dp[i][0]+1;
            dp[i+1][1]=3;
        }
    }
}

void printAns(){
    int k=n;
    cout<<dp[n][0]<<"\n";
    while(k>1){
        cout<<k<<" ";
        if(dp[k][1]==1) k/=3;
        else if(dp[k][1]==2) k/=2;
        else k-=1;
    }
    cout<<1<<"\n";
}