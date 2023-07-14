#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

void init();
void dfs(int,int,bool);
int getMinWorm(bool);

int n,normal,innormal;
char list[101][101];
int visited[101][101];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    cout<<getMinWorm(true)<<" ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    cout<<getMinWorm(false)<<"\n";
    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<n;j++){
            list[i][j]=str[j];
        }
    }
}

void dfs(int sr,int sc,bool mode){
    visited[sr][sc]=1;
    for(int i=0;i<4;i++){
        int mr=sr+dir[i][0];
        int mc=sc+dir[i][1];
        if(mr<0||mr>=n||mc<0||mc>=n) continue;
        if(visited[mr][mc]==1) continue;
        if(mode){
            if(list[sr][sc]!=list[mr][mc]) continue;
        }
        else{
            if(list[sr][sc]=='R'&&list[mr][mc]=='B')continue;
            if(list[sr][sc]=='G'&&list[mr][mc]=='B') continue;
            if(list[sr][sc]=='B'&&list[sr][sc]!=list[mr][mc]) continue;
        }
        dfs(mr,mc,mode);
    }
}

int getMinWorm(bool mode){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==1){
                continue;
            }
            dfs(i,j,mode);
            cnt++;
        }
    }
    return cnt;
}