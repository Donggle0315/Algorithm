#include <iostream>
using namespace std;

int isTriSum();
int tri(int);

int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        cout<<isTriSum()<<endl;
    }

    return 0;
}

int isTriSum(){
    int goal;
    cin>>goal;
    for(int i=1;i<goal;i++){
        if(tri(i)>=goal) break;
        for(int j=i;j<goal;j++){
            if(tri(i)+tri(j)>=goal) break;
            for(int k=j;k<goal;k++){
                if(tri(i)+tri(j)+tri(k)==goal) return 1;
                else if(tri(i)+tri(j)+tri(k)>goal) break;
            }
        }
    }
    return 0;
}

int tri(int a){
    return (a*(a+1))/2;
}