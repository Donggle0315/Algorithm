#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void init();
void finish();
long long binarySearch(long long,long long);
bool check(long long,long long*);

long long n,m,r;
long long* list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    cout<<binarySearch(0,r+1)<<endl;
    finish();

    return 0;
}

long long binarySearch(long long left, long long right){
    long long ans=-1;
    while(left<=right){
        long long mid=(left+right)/2;
        if(check(mid,&ans)){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return ans;
}

bool check(long long mid,long long* ans){
    long long sum=0;
    for(int i=0;i<n;i++){
        if(list[i]>mid) sum+=list[i]-mid;
    }
    if(sum>=m) {
        *ans=mid;
        return true;
    }
    return false;
}

void init(){
    cin>>n>>m;
    r=0;
    list=new long long[n];
    for(int i=0;i<n;i++){
        cin>>list[i];
        if(r<list[i]) r=list[i];
    }
}

void finish(){
    delete[] list;
}