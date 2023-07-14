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
long long getMinSum();

long long n;
int dice[6];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<getMinSum()<<"\n";

    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<6;i++){
        cin>>dice[i];
    }
}

long long getMinSum(){
    long long sum=0;
    vector<int> vec;
    vec.push_back(min(dice[0],dice[5]));
    vec.push_back(min(dice[1],dice[4]));
    vec.push_back(min(dice[2],dice[3]));
    sort(vec.begin(),vec.end());
    if(n==1){
        int m=dice[0];
        for(int i=0;i<6;i++){
            sum+=dice[i];
            if(dice[i]>m) m=dice[i];
        }
        sum-=m;
        return sum;
    }
    sum+=(vec[0]+vec[1]+vec[2])*4;
    sum+=((vec[0]+vec[1])*(8*n-12));
    sum+=(vec[0]*(5*n*n-16*n+12));
    return sum;
}

