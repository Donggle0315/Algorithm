#include <iostream>
using namespace std;



int main(){
    string coin;
    int zero=0,one=0;

    cin>>coin;
    
    if(coin[0]=='0') zero++;
    else one++;
    for(int i=1;i<coin.size();i++){
        if(coin[i]!=coin[i-1]){
            if(coin[i]=='0') zero++;
            else one++;
        }
    }
    cout<<min(zero,one)<<endl;
    return 0;
}

