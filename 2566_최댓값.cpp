#include <iostream>

using namespace std;

int main(){
    int max,row,col;
    max=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            int k;
            cin>>k;
            if(k>=max){
                row=i;
                col=j;
                max=k;
            }
        }
    }
    cout<<max<<endl;
    cout<<row<<" "<<col<<endl;
}