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
void solve();
int dijkstra(int,int);


vector<pii> vec[1001];
vector<int> route;
int visited[1001];
int vertex,edge,start,finish;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    cout<<dijkstra(start,finish)<<"\n";
    solve();

    return 0;
}

void init(){
    cin>>vertex>>edge;
    for(int i=0;i<edge;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(b,c));
    }
    cin>>start>>finish;
}

void solve(){
    int tmp=finish;
    while(true){
        route.push_back(tmp);
        if(tmp==start) break;
        tmp=visited[tmp];
    }
    cout<<route.size()<<"\n";
    for(int i=route.size()-1;i>=0;i--){
        cout<<route[i]<<" ";
    }
    cout<<"\n";
}

int dijkstra(int start_point, int end_point){
    priority_queue<pii> pq;
    int dist[20001];
    for(int i=1;i<=vertex;i++){
        dist[i]=INF;
    }
    dist[start_point]=0;
    pq.push(make_pair(0,start_point));
    while(!pq.empty()){
        int dis=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist[cur]<dis) continue;

        for(int i=0;i<vec[cur].size();i++){
            int next=vec[cur][i].first;
            int next_dist=vec[cur][i].second+dis;
            if(dist[next]>next_dist){
                dist[next]=next_dist;
                pq.push(make_pair(-next_dist,next));
                visited[next]=cur;
            }
        }
    }
    return dist[end_point];
}