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
#define INF 1e13+7
#define MOD 1004
typedef long long ll;
using namespace std;

void init();
void bellman_ford();
void print_dist();

int n,m;
ll list[501][501];
ll dist[501];
bool flag;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    bellman_ford();
    print_dist();
    return 0;
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) list[i][j]=0;
            else list[i][j]=INF;
        }
        dist[i]=INF;
    }
    dist[1]=0;
    for(int i=0;i<m;i++){
        int s,e,w;
        cin>>s>>e>>w;
        if(list[s][e]>w) list[s][e]=w;
    }
}

void bellman_ford(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[j]==INF) continue;
            for(int k=1;k<=n;k++){
                if(list[j][k]==INF) continue;;
                int nxt=k;
                ll dis=list[j][k];
                if(dist[nxt]>dist[j]+dis){
                    dist[nxt]=dist[j]+dis;
                    if(i==n) flag=true;
                }

            }
        }
    }
}

void print_dist(){
    if(flag) cout<<-1<<"\n";
    else{
        for(int i=2;i<=n;i++){
            if(dist[i]==INF) cout<<"-1\n";
            else cout<<dist[i]<<"\n";
        }
    }
    
}
