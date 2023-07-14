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
void finish();
int getMaxValue();

int n,k;
vector<pair<int,int> > vec;
int** dp;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<getMaxValue()<<"\n";
    finish();
    return 0;
}

void init(){
    cin>>n>>k;
    dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[k+1];
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
    }
}

void finish(){
    for(int i=0;i<=n;i++){
        delete[] dp[i];
    }
    delete[] dp;
}

int getMaxValue(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(vec[i-1].first<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-vec[i-1].first]+vec[i-1].second);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}
