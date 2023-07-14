#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int s;
        double avg=0;
        cin>>s;
        int* list=new int[s];
        for(int j=0;j<s;j++){
            cin>>list[j];
            avg+=list[j];
        }
        avg/=s;
        int up=0;
        for(int j=0;j<s;j++){
            if(list[j]>avg){
                up++;
            }
        }
        cout<<fixed;
        cout.precision(3);
        cout<<(double)up/s*100*1000/1000<<"%\n";
        delete[] list;
    }


    return 0;
}