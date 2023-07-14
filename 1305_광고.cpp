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

int n;
string str,pat;
int list[1000001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    return 0;
}

void init(){
    cin>>n>>str;
    pat=str;
    int j=0;
    for(int i=1;i<n;i++){
        while(j>0&&pat[j]!=str[i]){
            j=list[j-1];
        }
        if(pat[j]==str[i]) list[i]=++j;
    }
    cout<<n-list[n-1];
}
