#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 100000001
#define DIV 10007
using namespace std;

void init();
int getMaxValue();

int n,m,k;
int dp[101][301][301];
int burger[301];
int fries[301];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<getMaxValue()<<"\n";
    return 0;
}

void init(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>burger[i]>>fries[i];
    }
}


int getMaxValue(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int p=0;p<=k;p++){
                if(i==0||j==0||p==0) continue;
                else if(j>=burger[i]&&p>=fries[i]){
                    dp[i][j][p]=max(dp[i-1][j][p],dp[i-1][j-burger[i]][p-fries[i]]+1);
                }
                else {
                    dp[i][j][p]=dp[i-1][j][p];
                }
            }
        }
    }
    return dp[n][m][k];
}