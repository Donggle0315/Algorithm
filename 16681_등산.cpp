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
#define INF LLONG_MAX
#define MOD 1004
typedef long long ll;
using namespace std;

void init();
void dijkstra(int,ll*);
void print_dist();

int N,M,D,E;
vector<int> mountain;
vector<pii> vec[100001];
ll dist_up[100001];
ll dist_down[100001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    dijkstra(1,dist_up);
    dijkstra(N,dist_down);
    print_dist();
    return 0;
}

void init(){
    cin>>N>>M>>D>>E;
    mountain.push_back(0);
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        mountain.push_back(tmp);
    }
    for(int i=0;i<M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back(make_pair(v,w));
        vec[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=N;i++){
        dist_up[i]=INF;
        dist_down[i]=INF;
    }
    dist_up[1]=0;
    dist_down[N]=0;
}

void dijkstra(int start_point,ll* dist){
    priority_queue<pair<ll,int> > pq;
    pq.push(make_pair(0,start_point));
    while(!pq.empty()){
        ll dis=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist[cur]<dis) continue;

        for(int i=0;i<vec[cur].size();i++){
            int next=vec[cur][i].first;
            ll next_dist=vec[cur][i].second+dis;
            if(dist[next]>next_dist&&mountain[cur]<mountain[next]){
                dist[next]=next_dist;
                pq.push(make_pair(-next_dist,next));
            }
        }
    }
}

void print_dist(){
    ll ans=-INF;
    for(int i=2;i<=N;i++){
        if(dist_up[i]==INF||dist_down[i]==INF) continue;
        ans=max(ans,mountain[i]*E-(dist_up[i]+dist_down[i])*D);
    }
    if(ans==-INF){
        cout<<"Impossible\n";
    }
    else{
        cout<<ans<<"\n";
    }
}
