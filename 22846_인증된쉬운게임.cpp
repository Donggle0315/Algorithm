#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define INF 1000001
#define DIV 10007
using namespace std;

void getValue();

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    getValue();

    return 0;
}

void getValue(){
    int k;
    cin>>k;
    bool* list=new bool[k+1];
    for(int i=k;i>=1;i--){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if(i+j<=k&&!list[i+j]) {
                    list[i]=true;
                    break;
                }
                if(i+int(i/j)<=k&&!list[i+int(i/j)]) {
                    list[i]=true;
                    break;
                }
            }

        }
    }
    if(list[1]) cout<<"Kali\n";
    else cout<<"Ringo\n";
    delete[] list;
}