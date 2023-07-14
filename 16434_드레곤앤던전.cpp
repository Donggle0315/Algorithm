#include <iostream>
#include <algorithm>
using namespace std;

void init();
void finish();
long long binarySearch(long long,long long);
bool check(long long,long long*);

long long n,hatk;
long long r;
long long** list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    init();
    cout<<binarySearch(1,r)<<endl;
    finish();

    return 0;
}

long long binarySearch(long long left,long long right){
    long long ans=-1;
    while(left<=right){
        long long mid=(left+right)/2;
        if(check(mid,&ans)){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}

bool check(long long mid,long long* ans){
    long long curHP=mid;
    long long curAT=hatk;
    for(int i=0;i<n;i++){
        if(list[i][0]==1){
            long long turn=list[i][2]/curAT;
            if(list[i][2]%curAT!=0) turn++;
            curHP-=(list[i][1]*(turn-1));
        }
        else{
            curAT+=list[i][1];
            if(curHP+list[i][2]>mid) curHP=mid;
            else curHP=curHP+list[i][2];
        }
        if(curHP<=0) return false;
    }
    if(curHP>0) {
        *ans=mid;
        return true;
    }
    return false;
}

void init(){
    cin>>n>>hatk;
    r=0;
    list=new long long*[n];
    for(int i=0;i<n;i++){
        list[i]=new long long[3];
        cin>>list[i][0]>>list[i][1]>>list[i][2];
        if(list[i][0]==1){
            r+=list[i][1]*list[i][2];
        }
    }
}

void finish(){
    for(int i=0;i<n;i++){
        delete[] list[i];
    }
    delete[] list;
}