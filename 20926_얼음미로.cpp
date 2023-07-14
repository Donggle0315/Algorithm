#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <climits>
#include <cstring>
#define pii pair<int,int>
#define INF 1e7+7
#define MOD 1004
typedef long long ll;
using namespace std;

void init();
void dijkstra();
void print_dist();

int W,H;
int list[501][501];
int sRow,sCol,fRow,fCol;
int dist[501][501];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    dijkstra();
    print_dist();
    return 0;
}

void init(){
    cin>>W>>H;
    for(int i=0;i<H;i++){
        string str;
        cin>>str;
        for(int j=0;j<W;j++){
            if(str[j]=='T') list[i][j]=-1;
            else if(str[j]=='R') list[i][j]=-2;
            else if(str[j]=='H') list[i][j]=-3;
            else if(str[j]=='E') list[i][j]=-4;
            else list[i][j]=str[j]-'0';
            dist[i][j]=INF;
            if(list[i][j]==-1){
                sRow=i;
                sCol=j;
            }
            else if(list[i][j]==-4){
                fRow=i;
                fCol=j;
            }
        }
    }
}

void dijkstra(){
    priority_queue<pair<int,pii> > pq;
    dist[sRow][sCol]=0;
    pq.push(make_pair(0,make_pair(sRow,sCol)));
    while(!pq.empty()){
        int dis=-pq.top().first;
        int curR=pq.top().second.first;
        int curC=pq.top().second.second;
        pq.pop();

        if(dist[curR][curC]<dis) continue;

        for(int i=0;i<4;i++){
            int nextR=curR;
            int nextC=curC;
            int cost=0;
            while(1){
                if(nextR+dir[i][0]<0||nextR+dir[i][0]>=H||nextC+dir[i][1]<0||nextC+dir[i][1]>=W) break;
                if(list[nextR+dir[i][0]][nextC+dir[i][1]]==-1||list[nextR+dir[i][0]][nextC+dir[i][1]]==-2||list[nextR+dir[i][0]][nextC+dir[i][1]]==-3||list[nextR+dir[i][0]][nextC+dir[i][1]]==-4) break;
                nextR+=dir[i][0];
                nextC+=dir[i][1];
                cost+=list[nextR][nextC];
            }
            if(nextR+dir[i][0]<0||nextR+dir[i][0]>=H||nextC+dir[i][1]<0||nextC+dir[i][1]>=W||list[nextR+dir[i][0]][nextC+dir[i][1]]==-3) continue;
            else if(list[nextR+dir[i][0]][nextC+dir[i][1]]==-4){
                nextR+=dir[i][0];
                nextC+=dir[i][1];
            }
            if(dist[nextR][nextC]>dis+cost){
                dist[nextR][nextC]=dis+cost;
                pq.push(make_pair(-(dis+cost),make_pair(nextR,nextC)));
            }
        }
    }
}

void print_dist(){
    int ans=dist[fRow][fCol];
    if(ans==INF) cout<<-1<<"\n";
    else cout<<ans<<"\n";
}
