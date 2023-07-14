#include <iostream>

using namespace std;

int isHanSoo(int);

int main(){
    int n,count=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(isHanSoo(i)==1){
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}

int isHanSoo(int k){
    if(k<100){
        return 1;
    }
    int tmp=k/10;
    int d=k/10%10-k%10;
    
    while(tmp>=10){
        if(tmp/10%10-tmp%10!=d){
            return 0;
        }
        else{
            tmp/=10;
        }
    }
    return 1;
}