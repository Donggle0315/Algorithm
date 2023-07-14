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
void findRoute(int,int);
void print_dist();

int n,m;
int list[101][101][2];
vector<int> vec;

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
            if(i==j) list[i][j][0]=0;
            else list[i][j][0]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int s,e,w;
        cin>>s>>e>>w;
        if(list[s][e][0]>w) list[s][e][0]=w;
    }
}

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(list[i][j][0]>list[i][k][0]+list[k][j][0]){
                    list[i][j][0]=list[i][k][0]+list[k][j][0];
                    list[i][j][1]=k;
                }
            }
        }
    }
}

void findRoute(int start,int end){
    if(list[start][end][1]==0){
        vec.push_back(start);
        vec.push_back(end);
        return;
    }
    findRoute(start,list[start][end][1]);
    vec.pop_back();
    findRoute(list[start][end][1],end);
}

void print_dist(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(list[i][j][0]==INF) cout<<0<<" ";
            else cout<<list[i][j][0]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j||list[i][j][0]==INF) cout<<0<<"\n";
            else{
                vec.clear();
                findRoute(i,j);
                cout<<vec.size()<<" ";
                for(int k=0;k<vec.size();k++){
                    cout<<vec[k]<<" ";
                }
                cout<<"\n";
            }
        }
    }
}
