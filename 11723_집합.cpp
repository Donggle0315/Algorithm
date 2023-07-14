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
    
    int n;
    cin>>n;

    int idx,ans=0;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        if(tmp=="add"){
            cin>>idx;
            ans|=(1<<idx);
        }
        else if(tmp=="remove"){
            cin>>idx;
            ans&=~(1<<idx);
        }
        else if(tmp=="check"){
            cin>>idx;
            if(ans&(1<<idx)) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(tmp=="toggle"){
            cin>>idx;
            ans^=(1<<idx);
        }
        else if(tmp=="all"){
            ans=(1<<21)-1;
        }
        else if(tmp=="empty"){
            ans=0;
        }
    }
    return 0;
}