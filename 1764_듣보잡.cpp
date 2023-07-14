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
map<string,int> mp;
vector<string> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        mp.insert(pair<string,int>(tmp,1));
    }
    for(int i=0;i<m;i++){
        string tmp;
        cin>>tmp;
        if(mp.find(tmp)!=mp.end()){
            vec.push_back(tmp);
        }
    }
    sort(vec.begin(),vec.end());
    cout<<vec.size()<<"\n";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"\n";
    }

    return 0;
}
