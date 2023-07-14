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
int dfs(int,int);

int n,m;
string str,pat;
int list[501][501];
int dp[501][501];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    cout<<dfs(0,0)<<"\n";
    return 0;
}

int dfs(int row, int col){
    if(row==n-1&&col==m-1) return 1;
    if(dp[row][col]>=0) return dp[row][col];

    dp[row][col]=0;
    for(int i=0;i<4;i++){
        int nextRow=row+dir[i][0];
        int nextCol=col+dir[i][1];
        if(nextRow<0||nextRow>=n||nextCol<0||nextCol>=m) continue;
        if(list[row][col]>list[nextRow][nextCol]){
            dp[row][col]+=dfs(nextRow,nextCol);
        }
    }
    return dp[row][col];
}

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>list[i][j];
            dp[i][j]=-1;
        }
    }
}
