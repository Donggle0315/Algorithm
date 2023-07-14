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
#define MOD 1000
typedef long long ll;
using namespace std;

void init();
int solve();

int n;
int color[1001][3];
int dp[1001][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    cout<<solve()<<"\n";

    return 0;
}


void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int tmp;
            cin>>color[i][j];
            dp[i][j]=INF;
        }
    }
}

int solve(){
    int ans=INF;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j) dp[0][j]=color[0][j];
            else dp[0][j]=INF;
        }
        for(int j=1;j<n;j++){
            dp[j][0]=color[j][0]+min(dp[j-1][1],dp[j-1][2]);
            dp[j][1]=color[j][1]+min(dp[j-1][0],dp[j-1][2]);
            dp[j][2]=color[j][2]+min(dp[j-1][0],dp[j-1][1]);
        }
        for(int j=0;j<3;j++){
            if(i!=j) ans=min(ans,dp[n-1][j]);
        }
    }

    return ans;
}