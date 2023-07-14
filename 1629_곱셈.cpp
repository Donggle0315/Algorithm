#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void init();
long long divide(long long,long long);

long long a,b,c;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();  
    cout<<divide(a,b)<<endl;;

    return 0;
}

void init(){
    cin>>a>>b>>c;
}

long long divide(long long a, long long div){
    if(div==1){
        return a%c;
    }
    long long tmp=divide(a,div/2);
    if(div%2==0){
        return (tmp*tmp)%c;
    }
    else{
        return ((tmp*tmp)%c)*a%c;
    }
}