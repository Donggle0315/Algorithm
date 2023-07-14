#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 1000001
#define DIV 10007
using namespace std;

void init();
void finish();
int getLIS();

int n;
int* list;
int* dp;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<getLIS()<<"\n";
    finish();
    return 0;
}

void init(){
    cin>>n;
    list=new int[n+1];
    dp=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>list[i];
    }
}

void finish(){
    delete[] list;
    delete[] dp;
}

int getLIS(){
    int re=0;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int idx=0;
        for(int j=0;j<i;j++){
            if(list[i]>list[j]&&dp[j]>dp[idx]) idx=j;
        }
        dp[i]=dp[idx]+list[i];
        re=max(dp[i],re);
    }
    return re;
}
