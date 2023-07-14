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
#define INF 1e9+7
#define MOD 1004
typedef long long ll;
using namespace std;

void init();
void floyd();
void print_dist();

int n,m;
int list[101][101];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    floyd();
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
    }
    for(int i=0;i<m;i++){
        int s,e,w;
        cin>>s>>e>>w;
        if(list[s][e]>w) list[s][e]=w;
    }
}

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                list[i][j]=min(list[i][j],list[i][k]+list[k][j]);
            }
        }
    }
}

void print_dist(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(list[i][j]==INF) cout<<0<<" ";
            else cout<<list[i][j]<<" ";
        }
        cout<<"\n";
    }
}
