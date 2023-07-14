#include <iostream>

using namespace std;

int main(){
    //1,7,19,
    int n,k=1,count=0;
    cin>>n;
    for(int i=0;i<n;i++){
        if(k>=n){
            break;
        }
        k+=6*i;
        count++;
    }
    if(n==1){
        count=1;
    }
    cout<<count;

    return 0;
}