#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void init();
int getMinCoin();
int n,k;
vector<int> coin;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    cout<<getMinCoin()<<endl;
    

    return 0;
}

int getMinCoin(){
    int cnt=0;
    for(int i=coin.size()-1;i>=0;i--){
        cnt+=k/coin[i];
        k%=coin[i];
    }
    return cnt;
}

void init(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        coin.push_back(tmp);
    }
}
