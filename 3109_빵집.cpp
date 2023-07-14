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
int findRoute();
bool dfs(int,int);

int r,c,cnt;
char** list;
bool** visited;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<findRoute()<<"\n";
    finish();

    return 0;
}

void init(){
    cin>>r>>c;
    cnt=0;
    list=new char*[r];
    visited=new bool*[r];
    for(int i=0;i<r;i++){
        list[i]=new char[c];
        visited[i]=new bool[c];
        string tmp;
        cin>>tmp;
        for(int j=0;j<c;j++){
            list[i][j]=tmp[j];
            visited[i][j]=false;
        }
    }
}

void finish(){
    for(int i=0;i<r;i++){        
        delete[] list[i];
        delete[] visited[i];
    }
    delete[] list;
    delete[] visited;
}

int findRoute(){
    for(int i=0;i<r;i++){
        dfs(i,0);
    }
    return cnt;
}

bool dfs(int sr,int sc){
    visited[sr][sc]=true;
    int dirR[3]={-1,0,1};
    int dirC[3]={1,1,1};
    if(sc==c-1) {
        cnt++;
        return true;
    }
    for(int i=0;i<3;i++){
        int nr=sr+dirR[i];
        int nc=sc+dirC[i];
        if(nr<0||nr>=r||visited[nr][nc]||list[nr][nc]=='x') continue;
        if(dfs(nr,nc)) return true;
    }
    return false;
}