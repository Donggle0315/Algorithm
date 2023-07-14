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
void bfs();

int n,k;
bool visited[200001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    bfs();

    return 0;
}

void init(){
    cin>>n>>k;
}

void bfs(){
    int day=0;
    int cnt=0;
    queue<pii> qu;
    qu.push(make_pair(n,0));
    visited[n]=true;

    while(!qu.empty()){
        int pos=qu.front().first;
        int tim=qu.front().second;
        qu.pop();
        visited[pos]=true;
        if(cnt&&pos==k&&day==tim) cnt++;
        if(!cnt&&pos==k){
            day=tim;
            cnt++;
        }

        int nextpos=pos-1;
        if(nextpos>=0&&nextpos<=100000&&!visited[nextpos]){
            qu.push(make_pair(nextpos,tim+1));
        }
        nextpos=pos+1;
        if(nextpos>=0&&nextpos<=100000&&!visited[nextpos]){
            qu.push(make_pair(nextpos,tim+1));
        }
        nextpos=pos*2;
        if(nextpos>=0&&nextpos<=100000&&!visited[nextpos]){
            qu.push(make_pair(nextpos,tim+1));
        }

    }
    cout<<day<<"\n";
    cout<<cnt<<"\n";
}