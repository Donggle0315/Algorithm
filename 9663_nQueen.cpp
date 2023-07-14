#include <iostream>
#include <cmath>
using namespace std;

void init();
void finish();
void makeQueen(int);
bool isHere(int,int);

int n;
int* list;
int cnt=0;

int main(){
    init();
    makeQueen(0);
    cout<<cnt<<"\n";
    finish();

    return 0;
}

void makeQueen(int depth){
    if(depth==n){
        cnt++;
        return;
    }
    for(int j=0;j<n;j++){
        list[depth]=j;
        if(isHere(depth,j)) makeQueen(depth+1);
        list[depth]=-1;
    }
}

bool isHere(int row, int col){
    for(int i=0;i<row;i++){
        if(list[i]==col) return false;
        if(list[i]+i==row+col) return false;
        if(list[i]-i==col-row) return false;
    }
    return true;
}

void init(){
    cin>>n;
    list=new int[n];
    for(int i=0;i<n;i++){
        list[i]=-1;
    }
}

void finish(){
    delete[] list;
}