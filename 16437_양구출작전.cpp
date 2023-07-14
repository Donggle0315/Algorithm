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
ll dfs(int);

int n;
vector<int> vec[123457];
ll island[123457];


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    cout<<dfs(1)<<"\n";
    return 0;
}

void init(){
    cin>>n;
    for(int i=2;i<=n;i++){
        char animal;
        ll num,next;
        cin>>animal>>num>>next;
        vec[next].push_back(i);
        if(animal=='S') island[i]=num;
        else island[i]=-num;
    }
}

ll dfs(int start){
    if(vec[start].empty()){
        return island[start]>0?island[start]:0;
    }
    ll sum=0;
    sum+=island[start];
    for(int i=0;i<vec[start].size();i++){
        int tmp=vec[start][i];
        sum+=dfs(tmp);
    }

    return sum<0?0:sum;
}