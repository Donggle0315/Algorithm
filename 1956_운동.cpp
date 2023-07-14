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

int vertex,edge;
int list[401][401];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    floyd();
    return 0;
}

void init(){
    cin>>vertex>>edge;
    for(int i=1;i<=vertex;i++){
        for(int j=1;j<=vertex;j++){
            if(i==j) list[i][j]=0;
            else list[i][j]=INF;
        }
    }
    for(int i=0;i<edge;i++){
        int s,e,w;
        cin>>s>>e>>w;
        list[s][e]=w;
    }
}

void floyd(){
    int tmp=INF;
    for(int k=1;k<=vertex;k++){
        for(int i=1;i<=vertex;i++){
            for(int j=1;j<=vertex;j++){
                if(i==j&&i!=k){
                    tmp=min(tmp,list[i][k]+list[k][j]);
                }
                list[i][j]=min(list[i][j],list[i][k]+list[k][j]);
            }
        }
    }
    if(tmp==INF) cout<<-1<<"\n";
    else cout<<tmp<<"\n";
}