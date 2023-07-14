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
int getMinSum();

int n,m;
vector<int> pl;
vector<int> mi;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    sort(pl.begin(),pl.end());
    sort(mi.begin(),mi.end());
    cout<<getMinSum()<<"\n";

    return 0;
}

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp>0) pl.push_back(-1*tmp);
        else mi.push_back(tmp);
    }
    pl.push_back(0);
    mi.push_back(0);
}

int getMinSum(){
    int dis=0;
    int tmp=0;
    for(int i=0;i<mi.size();i+=m){
        dis+=(-2*mi[i]);
    }
    for(int i=0;i<pl.size();i+=m){
        dis+=(-2*pl[i]);
    }
    dis-=max(-1*mi[0],-1*pl[0]);
    return dis;
}

