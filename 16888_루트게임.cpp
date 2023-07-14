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

void getValue();

int list[INF];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    getValue();
    for(int i=0;i<tc;i++){
        int n;
        cin>>n;
        if(list[n]%2) cout<<"koosaga\n";
        else cout<<"cubelover\n";
    }

    return 0;
}

void getValue(){
    list[0]=0;
    for(int i=0;i<INF;i++){
        if(list[i]!=0) continue;
        for(int j=1;i+j*j<INF;j++){
            if(list[i+j*j]!=0) continue;
            list[i+j*j]=list[i]+1;
        }
    }
}