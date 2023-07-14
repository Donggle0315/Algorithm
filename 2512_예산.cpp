#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void init();
void finish();
int binarySearch(int,int);
bool check(int,int*);

int n,m;
int* list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    cout<<binarySearch(0,m)<<endl;
    finish();

    return 0;
}

int binarySearch(int left, int right){
    int ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(check(mid,&ans)){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return ans;
}

bool check(int mid,int* ans){
    int sum=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(list[i]<=mid) {
            sum+=list[i];
            if(list[i]>max) max=list[i];
        }
        else {
            sum+=mid;
            if(mid>max) max=mid;
        }
    }
    if(sum<=m) {
        *ans=max;
        return true;
    }
    return false;
}

void init(){
    cin>>n;
    list=new int[n];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    cin>>m;
}

void finish(){
    delete[] list;
}