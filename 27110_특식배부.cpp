#include <iostream>

using namespace std;

int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int sum=0;
    if(n<=a) sum+=n;
    else sum+=a;
    if(n<=b) sum+=n;
    else sum+=b;
    if(n<=c) sum+=n;
    else sum+=c;

    cout<<sum<<endl;

    return 0;
}