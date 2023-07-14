#include <iostream>

using namespace std;

int main(){
    int max=0,index;
    for(int i=1;i<10;i++){
        int a;
        cin>>a;
        if(a>max){
            max=a;
            index=i;
        }
    }
    cout<<max<<endl;
    cout<<index;

    return 0;
}