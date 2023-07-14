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

int n;
int dp[501][501];
vector<pii> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    cout<<solve()<<"\n";

    return 0;
}

void init(){
    cin>>n;
    vec.push_back(make_pair(0,0));
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
    }
}

int solve(){
    for(int i=1;i<n;i++){
        for(int j=1;i+j<=n;j++){
            dp[j][i+j]=INF;
            for(int k=j;k<=i+j;k++){
                dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+vec[j].first*vec[k].second*vec[i+j].second);
            }
        }
    }
    return dp[1][n];
}
