#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 1000001
#define DIV 10007
using namespace std;

void init();
void finish();
int getMinCoin();

int n,k;
int* coin;
int* dp;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<getMinCoin()<<"\n";
    finish();
    return 0;
}

void init(){
    cin>>n>>k;
    coin=new int[n];
    dp=new int[k+1];
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    for(int i=1;i<=k;i++){
        dp[i]=INF;
    }
}

void finish(){
    delete[] coin;
    delete[] dp;
}

int getMinCoin(){
    for(int i=0;i<n;i++){//n개의 동전에 대해
        for(int j=coin[i];j<=k;j++){//k원을 만드는 경우
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }
    if(dp[k]>=INF)return -1;
    return dp[k];
}
