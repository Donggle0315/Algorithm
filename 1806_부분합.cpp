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
int solve();

int n,s;
int num[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    cout<<solve()<<"\n";

    return 0;
}

void init(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
}

int solve(){
    int start=0, end=0, sum=0, len=INF;
    while(start<=end){
        if(sum>=s){
            len=min(len,end-start);
            sum-=num[start];
            start++;
        }
        else if(end==n) break;
        else {
            sum+=num[end];
            end++;
        }
    }
    if(len==INF) return 0;
    return len;
}
