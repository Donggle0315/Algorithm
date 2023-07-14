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

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        map<string,int> mp;
        cin>>n;
        for(int j=0;j<n;j++){
            string a,b;
            cin>>a>>b;
            if(mp.find(b)==mp.end()){
                mp.insert(pair<string,int>(b,1));
            }
            else{
                mp[b]++;
            }
        }
        int ans=1;
        for(auto i : mp){
            ans*=(i.second+1);
        }
        cout<<ans-1<<"\n";
    }
    return 0;
}