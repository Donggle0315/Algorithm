#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void init();
void divide(int,int,int);
void check(int,int,int);
void print(int);
void finish();

int n;
int **list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();  
    divide(0,0,n);  
    print(n);
    finish();

    return 0;
}

void init(){
    cin>>n;
    list=new int*[n];
    for(int i=0;i<n;i++){
        list[i]=new int[n];
    }
}

void finish(){
    for(int i=0;i<n;i++){
        delete[] list[i];
    }
    delete[] list;
}

void print(int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(list[i][j]==1) cout<<" ";
            else cout<<"*";
        }
        cout<<"\n";
    }
}

void divide(int startR,int startC, int size){
    if(size==1){
        return;
    }
    size/=3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1){
                check(startR+i*size,startC+j*size,size);
            }
            else{
                divide(startR+i*size,startC+j*size,size);
            }
        }
    }
}

void check(int sR,int sC,int size){
    for(int i=sR;i<sR+size;i++){
        for(int j=sC;j<sC+size;j++){
            list[i][j]=1;
        }
    }
}