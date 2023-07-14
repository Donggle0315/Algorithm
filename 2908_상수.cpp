#include <iostream>
#include <string>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int na=0,nb=0;
    for(int i=2;i>=0;i--){
        na*=10;
        na+=a[i]-'0';
        nb*=10;
        nb+=b[i]-'0';
    }

    if(na>nb){
        cout<<na<<endl;
    }
    else{
        cout<<nb<<endl;
    }


    return 0;
}