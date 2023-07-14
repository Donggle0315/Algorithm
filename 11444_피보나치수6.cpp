#include <iostream>
#include <algorithm>
#define DIV 1000000007
using namespace std;

void init();
long long divide();
void mulMatrix(long long[][2],long long[][2]);

long long n;
long long base[2][2]={{1,1},{1,0}};
long long result[2][2]={{1,0},{0,1}};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<divide()<<endl;
    

    return 0;
}

void init(){
    cin>>n;
}

long long divide(){
    while(n>0){
        if(n%2==1){
            mulMatrix(result,base);
        }
        n/=2;
        mulMatrix(base,base);
    }
    return result[1][0];
}

void mulMatrix(long long a[][2], long long b[][2]){
    long long tmp[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            tmp[i][j]=0;
            for(int k=0;k<2;k++){
                tmp[i][j]+=a[i][k]*b[k][j];
            }
            tmp[i][j]%=DIV;
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a[i][j]=tmp[i][j];
        }
    }
}