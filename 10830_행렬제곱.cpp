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
#define MOD 1000
typedef long long ll;
using namespace std;

void init();
void mat_mul(ll[][5],ll[][5]);
void getAns();

ll n,b;
ll ans[5][5];
ll A[5][5];
ll tmp[5][5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    getAns();

    return 0;
}


void init(){
    cin>>n>>b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
        ans[i][i]=1;
    }
}

void mat_mul(ll x[][5], ll y[][5]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j]=0;
            for(int k=0;k<n;k++){
                tmp[i][j]+=(x[i][k]*y[k][j]);
            }
            tmp[i][j]%=MOD;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x[i][j]=tmp[i][j];
        }
    }
}

void getAns(){
    while(b>0){
        if(b%2) mat_mul(ans,A);
        mat_mul(A,A);
        b/=2;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}