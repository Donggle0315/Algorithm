#include <iostream>
using namespace std;

int main(){
    string str;
    bool flag=true;
    cin>>str;
    for(int i=0,j=str.size()-1;i<j;i++,j--){
        if(str[i]!=str[j]){
            flag=false;
            break;
        } 
    }
    if(flag) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}