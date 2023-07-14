#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

void init();
void dfs(int,int);
void getMinWorm();
void finish();

int r,c,k;
int list[51][51];
int visited[51][51];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        init();
        getMinWorm();
        finish();
    }

    return 0;
}

void init(){
    cin>>c>>r>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        list[y][x]=1;
    }
}

void finish(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            list[i][j]=0;
            visited[i][j]=0;
        }
    }
}

void dfs(int sr,int sc){
    visited[sr][sc]=1;
    for(int i=0;i<4;i++){
        int mr=sr+dir[i][0];
        int mc=sc+dir[i][1];
        if(mr<0||mr>=r||mc<0||mc>=c) continue;
        if(visited[mr][mc]==1) continue;
        if(list[mr][mc]==0) continue;
        dfs(mr,mc);
    }
}

void getMinWorm(){
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(visited[i][j]==1){
                continue;
            }
            if(list[i][j]==0){
                continue;
            }
            dfs(i,j);
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}