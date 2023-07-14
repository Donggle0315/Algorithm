#include <iostream>

using namespace std;

int main(){
    int h,m,t;
    cin>>h>>m>>t;

    m+=(t%60);
    if(m>=60){
        h++;
    }
    m%=60;

    h+=(t/60);
    h%=24;

    cout<<h<<" "<<m;

    return 0;
}