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
void printPath();

int n,m;
int dp[21][301][2];
int list[21][301];
vector<int> vec;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    cout<<getMaxValue()<<"\n";
    printPath();

    return 0;
}

void printPath(){
    int tmp=n;
    for(int i=m;i>0;i--){
        vec.push_back(dp[i][tmp][1]);
        tmp-=dp[i][tmp][1];
    }
    for(int i=m-1;i>=0;i--){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

int getMaxValue(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<=j;k++){
                if(dp[i-1][j-k][0]+list[i][k]>dp[i][j][0]){
                    dp[i][j][0]=dp[i-1][j-k][0]+list[i][k];
                    dp[i][j][1]=k;
                }
            }
        }
    }
    return dp[m][n][0];
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        for(int j=1;j<=m;j++){
            cin>>list[j][t];
        }
    }
}