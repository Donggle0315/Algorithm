#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    string explode_str;
    string temp;
    cin>>str;
    cin>>explode_str;

    for(int i=0;i<str.length();i++){
        temp+=str[i];
        if(temp.length()>=explode_str.length()){
            bool flag=true;
            for(int j=0;j<explode_str.length();j++){
                if(temp[temp.length()-explode_str.length()+j]!=explode_str[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                temp.erase(temp.end()-explode_str.length(),temp.end());
            }
        }
    }

    if(temp.length()==0) cout<<"FRULA\n";
    else cout<<temp<<endl;

    return 0;
}