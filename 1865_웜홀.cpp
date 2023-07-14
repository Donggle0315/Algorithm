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

int n,m,w;
ll list[501][501];
ll dist[501];
bool flag;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        init();
        dist[1]=0;
        bellman_ford();
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

void init(){
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) list[i][j]=0;
            else list[i][j]=INF;
        }
        dist[i]=INF;
    }
    for(int i=0;i<m;i++){
        int s,e,t;
        cin>>s>>e>>t;
        if(list[s][e]>t) list[s][e]=t;
        if(list[e][s]>t) list[e][s]=t;
    }
    for(int i=0;i<w;i++){
        int s,e,t;
        cin>>s>>e>>t;
        if(list[s][e]>-t) list[s][e]=-t;
    }
    flag=false;
}

void bellman_ford(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //if(dist[j]==INF) continue;
            for(int k=1;k<=n;k++){
                //if(list[j][k]==INF) continue;;
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
