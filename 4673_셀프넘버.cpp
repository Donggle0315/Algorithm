#include <iostream>

using namespace std;

void selfNum(int);

int list[10001]={0};

int main(){
    for(int i=1;i<=10000;i++){
        if(list[i]!=0){
            continue;
        }
        selfNum(i);
    }
    for(int i=1;i<=10000;i++){
        if(list[i]==0){
            cout<<i<<endl;
        }
    }

    return 0;
}

void selfNum(int k){
    int tmp=k;
    while(tmp!=0){
        k+=tmp%10;
        tmp/=10;
    }
    if(k>10000){
        return;
    }
    list[k]=1;
    selfNum(k);
}