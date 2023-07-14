#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    int* list=new int[n];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    sort(list,list+n);

    cout<<list[n-k]<<endl;

    delete[] list;


    return 0;
}
