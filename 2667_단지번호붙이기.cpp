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

int r,cnt;
int list[26][26];
int visited[26][26];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    getMinWorm();
    sort(vec.begin(),vec.end());
    cout<<vec.size()<<"\n";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"\n";
    }
    return 0;
}

void init(){
    cin>>r;
    cnt=0;
    for(int i=0;i<r;i++){
        string str;
        cin>>str;
        for(int j=0;j<r;j++){
            list[i][j]=str[j]-'0';
        }
    }
}

void dfs(int sr,int sc){
    visited[sr][sc]=1;
    cnt++;
    for(int i=0;i<4;i++){
        int mr=sr+dir[i][0];
        int mc=sc+dir[i][1];
        if(mr<0||mr>=r||mc<0||mc>=r) continue;
        if(visited[mr][mc]==1) continue;
        if(list[mr][mc]==0) continue;
        dfs(mr,mc);
    }
}

void getMinWorm(){
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            if(visited[i][j]==1){
                continue;
            }
            if(list[i][j]==0){
                continue;
            }
            dfs(i,j);
            vec.push_back(cnt);
            cnt=0;
        }
    }
}