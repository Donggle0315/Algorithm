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
void cal(int,int,int);

int n;
int list[128][128];
int white,blue;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    cal(0,0,n);
    cout<<white<<"\n"<<blue<<"\n";

    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>list[i][j];
        }
    }
    white=0;
    blue=0;
}

void cal(int row,int col, int dep){
    int k=list[row][col];
    bool flag=false;
    for(int i=0;i<dep;i++){
        for(int j=0;j<dep;j++){
            if(list[row+i][col+j]!=k){
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(!flag){
        if(k==0) white++;
        else blue++;
    }
    else{
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cal(row+i*(dep/2),col+j*(dep/2),(dep/2));
            }
        }
    }
}