#include <iostream>

using namespace std;

int main(){
    int n,k,count=0;;
    cin>>n;
    k=n;
    while(1){
        k=(k%10)*10+(k/10+k%10)%10;
        count++;
        if(n==k){
            break;
        }
    }
    cout<<count;

    return 0;
}