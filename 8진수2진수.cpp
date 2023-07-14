#include <iostream>
using namespace std;

string octTobin(int);

int main(){
    string octa;
    string result="";
    cin>>octa;
    for(int i=0;i<octa.size();i++){
        result+=octTobin(octa[i]-'0');
    }
    bool flag=false;
    if(octa=="0"){
        cout<<"0";
    }
    else{
        for(int i=0;i<result.size();i++){
            if(!flag&&result[i]=='0') continue;
            flag=true;
            cout<<result[i];
        }
    }
    
    cout<<endl;
    return 0;
}

string octTobin(int o){
    string result="";
    if(o>=4){
        result+="1";
        o-=4;
    }
    else result+="0";
    if(o>=2){
        result+="1";
        o-=2;
    }
    else result+="0";
    if(o>=1){
        result+="1";
        o-=1;
    }
    else result+="0";
    return result;
}