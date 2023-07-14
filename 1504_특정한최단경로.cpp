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
#define INF 1e8+7
#define MOD 1004
typedef long long ll;
using namespace std;

void init();
int dijkstra(int,int);

int vertex,edge,v1,v2;
vector<pii> vec[20001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    ll s1=dijkstra(1,v1)+dijkstra(v1,v2)+dijkstra(v2,vertex);
    ll s2=dijkstra(1,v2)+dijkstra(v2,v1)+dijkstra(v1,vertex);
    if(s1>=INF&&s2>=INF) cout<<-1<<"\n";
    else cout<<min(s1,s2)<<"\n";
    return 0;
}

void init(){
    cin>>vertex>>edge;
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back(make_pair(v,w));
        vec[v].push_back(make_pair(u,w));
    }
    cin>>v1>>v2;
}

int dijkstra(int start_point, int end_point){
    priority_queue<pii> pq;
    ll dist[20001];
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
            }
        }
    }
    return dist[end_point];
}
