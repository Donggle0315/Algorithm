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
int bfs(int);
 
int n,k;
bool visited[100002];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<bfs(n)<<"\n";
    
    return 0;
}

void init(){
    cin>>n>>k;
}

int bfs(int start){
    int ans=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int time=pq.top().first;
        int pos=pq.top().second;
        pq.pop();

        if(pos==k){
            ans=time;
            break;
        }
        for(int i=0;i<3;i++){
            if(i==0){
                int nextPos=pos*2;
                if(nextPos<0||nextPos>100000) continue;
                if(visited[nextPos]) continue;
                pq.push(make_pair(time,nextPos));
                visited[nextPos]=true;
            }
            else if(i==1){
                int nextPos=pos-1;
                if(nextPos<0||nextPos>100000) continue;
                if(visited[nextPos]) continue;
                pq.push(make_pair((time+1),nextPos));
                visited[nextPos]=true;
            }
            else{
                int nextPos=pos+1;
                if(nextPos<0||nextPos>100000) continue;
                if(visited[nextPos]) continue;
                pq.push(make_pair((time+1),nextPos));
                visited[nextPos]=true;
            }
        }
    }
    return ans;
}
