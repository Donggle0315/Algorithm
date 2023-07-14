#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 1000001
using namespace std;

void init();
int cntMin();

int n;
int* list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<cntMin()<<"\n";
    delete[] list;
    return 0;
}

void init(){
    cin>>n;
    list=new int[n+1];
    if(n>=1) list[1]=0;
    if(n>=2) list[2]=1;
    if(n>=3) list[3]=1;
    for(int i=4;i<=n;i++){
        list[i]=INF;
    }
}

int cntMin(){
    if(n<=3) return list[n];
    for(int i=4;i<=n;i++){
        if(i%3==0&&list[i/3]+1<list[i]) list[i]=list[i/3]+1;
        if(i%2==0&&list[i/2]+1<list[i]) list[i]=list[i/2]+1;
        if(list[i-1]+1<list[i]) list[i]=list[i-1]+1; 
    }
    return list[n];
}
