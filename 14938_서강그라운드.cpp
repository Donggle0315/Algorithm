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
void findMaxValue();
void dijkstra(int);
int print_dist();

int vertex,m,edge;
vector<int> items;
vector<pii> vec[20001];
int dist[20001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    findMaxValue();
    return 0;
}

void init(){
    cin>>vertex>>m>>edge;
    for(int i=1;i<=vertex;i++){
        int tmp;
        cin>>tmp;
        items.push_back(tmp);
        dist[i]=INF;
    }
    for(int i=0;i<edge;i++){
        int s,e,w;
        cin>>s>>e>>w;
        vec[s].push_back(make_pair(e,w));
        vec[e].push_back(make_pair(s,w));
    }
}

void findMaxValue(){
    int max=0;
    for(int i=1;i<=vertex;i++){
        dist[i]=0;
        dijkstra(i);
        int tmp=print_dist();
        if(tmp>max) max=tmp;
        for(int i=1;i<=vertex;i++){
            dist[i]=INF;
        }
    }
    cout<<max<<"\n";
}

void dijkstra(int start_point){
    priority_queue<pii> pq;
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
}

int print_dist(){
    int sum=0;
    for(int i=1;i<=vertex;i++){
        if(dist[i]<=m){
            sum+=items[i-1];
        } 
    }
    return sum;
}
