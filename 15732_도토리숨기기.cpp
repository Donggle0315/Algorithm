#include <iostream>
#include <algorithm>
using namespace std;

void init();
void finish();
int binarySearch(int,int);
bool check(int,int*);

int n,k,d;
int** list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    cout<<binarySearch(0,n)<<endl;
    finish();

    return 0;
}

int binarySearch(int left,int right){
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
    long long sum=0;
    for(int i=0;i<k;i++){
        int tmp=min(list[i][1],mid);
        if(tmp>=list[i][0]) sum+=(tmp-list[i][0])/list[i][2]+1;
    }
    if(sum>=d) {
        *ans=mid;
        return true;
    }
    return false;
}

void init(){
    cin>>n>>k>>d;
    list=new int*[k];
    for(int i=0;i<k;i++){
        list[i]=new int[3];
        cin>>list[i][0]>>list[i][1]>>list[i][2];
    }
}

void finish(){
    for(int i=0;i<k;i++){
        delete[] list[i];
    }
    delete[] list;
} 