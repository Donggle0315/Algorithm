#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

void init();
int bfs(int,int);

int n,m;
int list[1001][1001];
int visited[1001][1001][2];
queue<pair<pair<int,int>,int> > qu;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    cout<<bfs(0,0)<<"\n";
    return 0;
}

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<m;j++){
            list[i][j]=tmp[j]-'0';
        }
    }
}

int bfs(int sr,int sc){
    qu.push(make_pair(make_pair(sr,sc),1));
    visited[sr][sc][1]=1;
    while(!qu.empty()){
        int nr=qu.front().first.first;
        int nc=qu.front().first.second;
        int bl=qu.front().second;
        qu.pop();
        if(nr==n-1&&nc==m-1) return visited[nr][nc][bl];
        for(int i=0;i<4;i++){
            int mr=nr+dir[i][0];
            int mc=nc+dir[i][1];
            if(mr<0||mr>=n||mc<0||mc>=m) continue;
            if(list[mr][mc]==1&&bl){
                visited[mr][mc][bl-1]=visited[nr][nc][bl]+1;
                qu.push(make_pair(make_pair(mr,mc),bl-1));
            }
            if(list[mr][mc]==0&&visited[mr][mc][bl]==0){
                visited[mr][mc][bl]=visited[nr][nc][bl]+1;
                qu.push(make_pair(make_pair(mr,mc),bl));
            }
        }
    }
    return -1;
}