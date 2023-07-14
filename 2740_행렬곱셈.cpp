#include <iostream>
#include <algorithm>
using namespace std;

void init();
void finish();

int n,m,k;
int** matA;
int** matB;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int re=0;
            for(int x=0;x<m;x++){
                re+=(matA[i][x]*matB[x][j]);
            }
            cout<<re<<" ";
        }
        cout<<"\n";
    }
    finish();

    return 0;
}

void init(){
    cin>>n>>m;
    matA=new int*[n];
    for(int i=0;i<n;i++){
        matA[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>matA[i][j];
        }
    }
    cin>>m>>k;
    matB=new int*[m];
    for(int i=0;i<m;i++){
        matB[i]=new int[k];
        for(int j=0;j<k;j++){
            cin>>matB[i][j];
        }
    }
}

void finish(){
    for(int i=0;i<n;i++){
        delete[] matA[i];
    }
    for(int i=0;i<m;i++){
        delete[] matB[i];
    }
    delete[] matA;
    delete[] matB;
}
