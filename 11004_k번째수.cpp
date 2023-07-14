#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int n,k;
    int* list;
    cin>>n>>k;
    list=new int[n];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    sort(&list[0],&list[n]);
    cout<<list[k-1]<<endl;

    return 0;
}
