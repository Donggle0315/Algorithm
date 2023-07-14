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
int getBC();

int n,k;
int** list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<getBC()<<"\n";
    finish();
    return 0;
}

void init(){
    cin>>n>>k;
    k=n-k>k?k:n-k;
    list=new int*[n+1];
    for(int i=0;i<=n;i++){
        list[i]=new int[k+1];
        for(int j=0;j<=k;j++){
            if(i==j||j==0) list[i][j]=1;
        }
    }
}

void finish(){
    for(int i=0;i<=n;i++){
        delete[] list[i];
    }
    delete[] list;
}

int getBC(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            list[i][j]=(list[i-1][j]+list[i-1][j-1])%DIV;
        }
    }
    return list[n][k];
}
