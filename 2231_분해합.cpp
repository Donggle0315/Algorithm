#include <iostream>
using namespace std;

int main(){
    int n,i;
    bool flag=false;
    cin>>n;

    for(i=1;i<n;i++){
        int tmp=i;
        int sum=tmp;
        while(tmp!=0){
            sum+=tmp%10;
            tmp/=10;
        }
        if(sum==n){
            flag=true;
            break;
        }
    }
    if(flag) cout<<i<<endl;
    else cout<<0<<endl;

    return 0;
}