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
int solve();

int n,m,sum;
int application[101][101];
int dp[101][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    cout<<solve()<<"\n";

    return 0;
}

void init(){
    sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>application[i][0];
        
    }
    for(int i=1;i<=n;i++){
        cin>>application[i][1];
        sum+=application[i][1];
    }
}

int solve(){
    int ans=-1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j-application[i][1]>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-application[i][1]]+application[i][0]);
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(i==n&&ans==-1&&dp[i][j]>=m) ans=j;
        }
    }
    return ans;
}
