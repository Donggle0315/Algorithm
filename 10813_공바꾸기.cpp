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

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int list[101];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        list[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        swap(list[a],list[b]);
    }
    for(int i=1;i<=n;i++){
        cout<<list[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
