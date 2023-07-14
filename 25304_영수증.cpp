#include <iostream>

using namespace std;

int main(){
    int sum=0,total,n;
    cin>>total>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sum+=a*b;
    }
    if(sum==total){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}