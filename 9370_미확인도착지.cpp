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
void dijkstra(int,int*);
void getAns();
 
int n,m,t,s,g,h;
vector<pii> list[2001];
vector<int> dest;
int dist1[2001];
int dist2[2001];
int dist3[2001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        init();
        dijkstra(s,dist1);
        dijkstra(g,dist2);
        dijkstra(h,dist3);
        getAns();
    }
    return 0;
}

void init(){
    cin>>n>>m>>t;
    cin>>s>>g>>h;
    for(int i=0;i<2001;i++){
        list[i].clear();
    }
    dest.clear();
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        list[a].push_back(make_pair(b,c));
        list[b].push_back(make_pair(a,c));
    }
    for(int i=0;i<t;i++){
        int tmp;
        cin>>tmp;
        dest.push_back(tmp);
    }
}

void getAns(){
    sort(dest.begin(),dest.end());
    for(int i=0;i<dest.size();i++){
        if(dist1[dest[i]]==(dist1[g]+dist2[h]+dist3[dest[i]])) cout<<dest[i]<<" ";
        else if(dist1[dest[i]]==(dist1[h]+dist3[g]+dist2[dest[i]])) cout<<dest[i]<<" "; 
    }
    cout<<"\n";
}

void dijkstra(int start_point, int* dist){
    priority_queue<pii> pq;
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    dist[start_point]=0;
    pq.push(make_pair(0,start_point));
    while(!pq.empty()){
        int dis=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist[cur]<dis) continue;

        for(int i=0;i<list[cur].size();i++){
            int next=list[cur][i].first;
            int next_dist=list[cur][i].second+dis;
            if(dist[next]>next_dist){
                dist[next]=next_dist;
                pq.push(make_pair(-next_dist,next));
            }
        }
    }
}
