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
int solve(int);


vector<pii> vec[100001];
bool visited[100001];
int n,ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    solve(1);
    cout<<ans<<"\n";

    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        int start;
        cin>>start;
        while(true){
            int end;
            cin>>end;
            if(end==-1) break;
            int dist;
            cin>>dist;
            vec[start].push_back(make_pair(end,dist));
        }
    }
    ans=0;
}

int solve(int ver){
    visited[ver]=true;
    int max=0;
    int tmp=0;
    for(int i=0;i<vec[ver].size();i++){
        if(visited[vec[ver][i].first]) continue;
        tmp=vec[ver][i].second+solve(vec[ver][i].first);
            if(max+tmp>ans){
            ans=max+tmp;
        }
        if(tmp>max) max=tmp;
    }
    visited[ver]=false;
    return max;
}