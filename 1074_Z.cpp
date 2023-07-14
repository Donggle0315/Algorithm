#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int divide(int,int,int,int);

int n,row,col;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    cin>>n>>row>>col;
    cout<<divide(0,0,(int)pow(2,n),0)<<endl;

    return 0;
}

int divide(int startR,int startC, int size,int count){
    if(size==1){
        return count;
    }
    if(startR<=row&&row<startR+size/2&&startC<=col&&col<startC+size/2) {
        return divide(startR,startC,size/2,count);
    }
    count+=size/2*size/2;
    if(startR<=row&&row<startR+size/2&&startC+size/2<=col&&col<startC+size) {
        return divide(startR,startC+size/2,size/2,count);
    }
    count+=size/2*size/2;
    if(startR+size/2<=row&&row<startR+size&&startC<=col&&col<startC+size/2) {
        return divide(startR+size/2,startC,size/2,count);
    }
    count+=size/2*size/2;
    if(startR+size/2<=row&&row<startR+size&&startC+size/2<=col&&col<startC+size) {
        return divide(startR+size/2,startC+size/2,size/2,count);
    }
    return -1;
}