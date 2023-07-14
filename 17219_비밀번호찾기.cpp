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

int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    map<string,string> mp;

    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        mp.insert(pair<string,string>(a,b));
    }
    for(int i=0;i<m;i++){
        string a;
        cin>>a;
        cout<<mp[a]<<"\n";
    }
    return 0;
}