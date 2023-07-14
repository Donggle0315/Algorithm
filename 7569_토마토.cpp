#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

void init();
bool isAllClear();
void bfs();

int r,c,h,day;
int list[101][101][101][2];
bool visited[101][101][101];
int dir[6][3]={{0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{-1,0,0},{1,0,0}};
queue<pair<int,pair<int, int> > > qu;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    bfs();
    if(isAllClear()) cout<<day<<"\n";
    else cout<<-1<<"\n";

    return 0;
}

void init(){
    day=0;
    cin>>c>>r>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                cin>>list[i][j][k][0];
                if(list[i][j][k][0]==1) qu.push(make_pair(i,make_pair(j,k)));
                visited[i][j][k]=true;
            }
        }
    }
}

void bfs(){
    while(!qu.empty()){
        int nh=qu.front().first;
        int nr=qu.front().second.first;
        int nc=qu.front().second.second;
        qu.pop();
        if(list[nh][nr][nc][1]>day) day=list[nh][nr][nc][1];
        for(int i=0;i<6;i++){
            int mh=nh+dir[i][0];
            int mr=nr+dir[i][1];
            int mc=nc+dir[i][2];
            if(mh<0||mh>=h||mr<0||mr>=r||mc<0||mc>=c) continue;
            if(!visited[mh][mr][mc]) continue;
            if(list[mh][mr][mc][0]!=0) continue;
            list[mh][mr][mc][0]=1;
            list[mh][mr][mc][1]=list[nh][nr][nc][1]+1;
            visited[mh][mr][mc]=true;
            qu.push(make_pair(mh,make_pair(mr,mc)));
        }
    }
}

bool isAllClear(){
    for(int i=0;i<h;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                if(list[i][j][k][0]==0) return false;
            }
        }
    }
    return true;
}