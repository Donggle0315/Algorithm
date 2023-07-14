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
void dfs(int);
void bfs(int);
void finish();

int n,m,start;
vector<int> vec[10001];
bool* dfs_visited;
bool* bfs_visited;
queue<int> qu;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    dfs(start);
    cout<<"\n";
    bfs(start);
    cout<<"\n";
    finish();

    return 0;
}

void init(){
    cin>>n>>m>>start;
    for(int i=0;i<m;i++){
        int sv,ev;
        cin>>sv>>ev;
        vec[sv].push_back(ev);
        vec[ev].push_back(sv);
    }
    dfs_visited=new bool[n+1];
    bfs_visited=new bool[n+1];
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(),vec[i].end());
    }
}

void finish(){
    delete[] dfs_visited;
    delete[] bfs_visited;
}

void dfs(int s){
    dfs_visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<vec[s].size();i++){
        if(!dfs_visited[vec[s][i]]) dfs(vec[s][i]);
    }
}

void bfs(int s){
    bfs_visited[s]=true;
    qu.push(s);
    while(!qu.empty()){
        int tmp=qu.front();
        qu.pop();
        cout<<tmp<<" ";
        for(int i=0;i<vec[tmp].size();i++){
            if(!bfs_visited[vec[tmp][i]]) {
                qu.push(vec[tmp][i]);
                bfs_visited[vec[tmp][i]]=true;
            }
        }
    }
}