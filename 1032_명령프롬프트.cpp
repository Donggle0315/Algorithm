#include <iostream>
using namespace std;

int main(){
    int tc;
    string* list;
    string result="";
    cin>>tc;
    list=new string[tc];
    for(int i=0;i<tc;i++){
        cin>>list[i];
    }

    for(int i=0;i<list[0].size();i++){
        bool flag=true;
        for(int j=1;j<tc;j++){
            if(list[0][i]!=list[j][i]){
                flag=false;
                break;
            }
        }
        if(flag) result+=list[0][i];
        else result+="?";
    }

    cout<<result<<endl;
    
    delete[] list;
    return 0;
}