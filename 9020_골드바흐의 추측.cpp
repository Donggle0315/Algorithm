#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void findGoldBah(int*,int*,int);
void makeSosu();

vector<int> sosu;

int main(){
    int testCase;
    cin>>testCase;
    makeSosu();
    for(int i=0;i<testCase;i++){
        int a=1,b=10000,n;
        cin>>n;
        findGoldBah(&a,&b,n);
        cout<<a<<" "<<b<<endl;
    }

    return 0;
}

void makeSosu(){
    sosu.push_back(2);
    int i,j;
    for(i=3;i<10000;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }
        }
        if(i==j){
            sosu.push_back(i);
        }
    }
}

void findGoldBah(int* a,int* b,int n){
    for(int i=0;;i++){
        if(sosu[i]>=n){
            break;
        }
        for(int j=0;j<=i;j++){
            if(sosu[i]+sosu[j]==n){
                if(abs((*a)-(*b))>abs(sosu[i]-sosu[j])){
                    (*a)=sosu[j];
                    (*b)=sosu[i];
                }
            }
        }
    }
}
