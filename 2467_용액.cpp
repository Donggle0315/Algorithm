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
#define INF 1e13+7
#define MOD 1004
typedef long long ll;
using namespace std;

void init();
void solve();

int n;
ll list[100000];
ll ans;
ll ans_list[3];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    solve();

    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    sort(&list[0],&list[n]);
    ans=INF;
}

void solve(){
    int l=0;
    int r=n-1;
    while(l<r){
        ll mid=list[l]+list[r];
        if(abs(mid)<ans){
            ans=abs(mid);
            ans_list[0]=list[l];
            ans_list[1]=list[r];
        }
        if(mid>=0) r--;
        else l++;
    }
    cout<<ans_list[0]<<" "<<ans_list[1]<<"\n";
}
