#include <iostream>
#include <algorithm>
using namespace std;

void init();
void finish();
void makeSequence(int,int);

int n,m;
int* list;
int* result;

int main(){
    init();
    makeSequence(0,0);
    finish();

    return 0;
}

void init(){
    cin>>n>>m;
    list=new int[n];
    result=new int[m];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    sort(&list[0],&list[n]);
}

void finish(){
    delete[] list;
    delete[] result;
}

void makeSequence(int depth,int idx){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=idx;i<n;i++){
        result[depth]=list[i];
        makeSequence(depth+1,i);
    }
}