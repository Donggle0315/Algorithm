#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int max=0;
    int* list;
    list=new int[n];
    for(int i=0;i<n;i++){
        cin>>list[i];
        if(list[i]>max){
            max=list[i];
        }
    }
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=(((double)list[i]/max)*100);
    }
    sum/=n;
    cout<<sum;
    delete[] list;

    return 0;
}