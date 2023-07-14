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


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int* dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+1,dp[i-3]+1);
    }
    if(dp[n]%2) cout<<"SK\n";
    else cout<<"CY\n";
    delete[] dp;
    return 0;
}
