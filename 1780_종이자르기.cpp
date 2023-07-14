#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void init();
void divide(int,int,int);
bool check(int,int,int);
void finish();

int n;
int cnt[3]={0};
int **list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();  
    divide(0,0,n);  
    cout<<cnt[0]<<"\n"<<cnt[1]<<"\n"<<cnt[2]<<"\n";
    finish();

    return 0;
}

void init(){
    cin>>n;
    list=new int*[n];
    for(int i=0;i<n;i++){
        list[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>list[i][j];
        }
    }
}

void finish(){
    for(int i=0;i<n;i++){
        delete[] list[i];
    }
    delete[] list;
}

void divide(int startR,int startC, int size){
    if(check(startR,startC,size)){
        cnt[list[startR][startC]+1]+=1;
        return;
    }
    size/=3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(check(startR+i*size,startC+j*size,size)){
                cnt[list[startR+i*size][startC+j*size]+1]+=1;
            }
            else{
                divide(startR+i*size,startC+j*size,size);
            }
        }
    }
}

bool check(int sR,int sC,int size){
    int tmp=list[sR][sC];
    for(int i=sR;i<sR+size;i++){
        for(int j=sC;j<sC+size;j++){
            if(tmp!=list[i][j]) return false;
        }
    }
    return true;
}