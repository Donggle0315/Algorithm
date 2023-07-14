#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void init();
void finish();
int binarySearch(int,int);
bool check(int,int*);

int n,m,r;
int* list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    cout<<binarySearch(r,r*n)<<endl;
    finish();

    return 0;
}

int binarySearch(int left, int right){
    int ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(check(mid,&ans)){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}

bool check(int mid,int* ans){
    int sum=0;
    int count=1;
    for(int i=0;i<n;i++){
        if(sum+list[i]>mid){
            sum=0;
            count++;
        }
        sum+=list[i];
    }
    if(count<=m) {
        *ans=mid;
        return true;
    }
    return false;
}

void init(){
    cin>>n>>m;
    list=new int[n];
    for(int i=0;i<n;i++){
        cin>>list[i];
        if(r<list[i]) r=list[i];
    }
}

void finish(){
    delete[] list;
}