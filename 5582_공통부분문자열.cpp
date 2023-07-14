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
void findLCS();

string s1,s2;
int dp[4001][4001];
int lens1,lens2;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    findLCS();
    return 0;
}

void init(){
    cin>>s1>>s2;
    lens1=s1.size();
    lens2=s2.size();
}

void findLCS(){
    dp[0][0]=0;
    int ans=0;
    for(int i=0;i<lens1;i++){
        for(int j=0;j<lens2;j++){
            if(s1[i]==s2[j]){
                if(i==0||j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1]+1;
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<"\n";
}