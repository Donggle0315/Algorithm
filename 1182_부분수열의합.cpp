#include <iostream>
using namespace std;

void subSum(int,int);

int n,s,cnt;
int* list;
int count;

int main(){
    cin>>n>>s;
    cnt=0;
    list=new int[n];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    subSum(0,0);
    if(s==0) cnt--;
    cout<<cnt<<endl;

    return 0;
}

void subSum(int idx,int sum){
    if(idx==n){
        if(sum==s) cnt++;
        return;
    }
    subSum(idx+1,sum+list[idx]);
    subSum(idx+1,sum);
}