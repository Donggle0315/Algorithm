#include <iostream>

using namespace std;

#define DIV 42

int main(){
    int list[10];
    int count=10;
    for(int i=0;i<10;i++){
        int a;
        cin>>a;
        list[i]=a%DIV;
        for(int j=0;j<i;j++){
            if(list[i]==list[j]){
                count--;
                break;
            }
        }
    }
    cout<<count;

    
    return 0;
}