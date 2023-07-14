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
ll list[5000];
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
    for(int i=0;i<n-2;i++){
        int l=i+1;
        int r=n-1;
        while(l<r){
            ll tmp=list[i]+list[l]+list[r];
            if(abs(tmp)<ans){
                ans=abs(tmp);
                ans_list[0]=list[i];
                ans_list[1]=list[l];
                ans_list[2]=list[r];
            }
            if(tmp>=0) r--;
            else l++; 
        }
    }
    sort(&ans_list[0],&ans_list[3]);
    cout<<ans_list[0]<<" "<<ans_list[1]<<" "<<ans_list[2]<<"\n";
}
