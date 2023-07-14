#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


void init();
void finish();
int countArea();
void bfs(int,int);


int** list;
int** visited;
int n,m;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int> > qu;

int main(){    
    init();
    cout<<countArea()<<endl;
    finish();

    return 0;
}

void bfs(int row, int col){
    qu.push(make_pair(row,col));
    visited[row][col]=1;
    while(!qu.empty()){
        int r=qu.front().first;
        int c=qu.front().second;
        qu.pop();
        for(int i=0;i<4;i++){
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(nr<0) nr=n-1;
            if(nr>=n) nr=0;
            if(nc<0) nc=m-1;
            if(nc>=m) nc=0;
            if(visited[nr][nc]==1) continue;
            if(list[nr][nc]==1) continue;
            qu.push(make_pair(nr,nc));
            visited[nr][nc]=1;
        }
    }
}

int countArea(){
    int area=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(list[i][j]==0&&visited[i][j]==0){
                bfs(i,j);
                area++;
            }
        }
    }
    return area;
}

void init(){
    cin>>n>>m;
    list=new int*[n];
    visited=new int*[n];
    for(int i=0;i<n;i++){
        list[i]=new int[m];
        visited[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>list[i][j];
        }
    }
}

void finish(){
    for(int i=0;i<n;i++){
        delete[] list[i];
        delete[] visited[i];
    }
    delete[] list;
    delete[] visited;
}