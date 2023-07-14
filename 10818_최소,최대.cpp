#include <iostream>

using namespace std;

int main(){
    int n,max=-1000001,min=1000001;

    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>max){
            max=a;
        }
        if(a<min){
            min=a;
        }
    }

    cout<<min<<" "<<max;
    
    return 0;
}