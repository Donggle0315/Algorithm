#include <iostream>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        string s;
        int split;
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]==','){
                split=j;
                break;
            }
        }
        int a=0;
        for(int j=0;j<split;j++,a*=10){
            a+=s[j]-'0';
        }
        a/=10;
        int b=0;
        for(int j=split+1;j<s.size();j++,b*=10){
            b+=s[j]-'0';
        }
        b/=10;
        cout<<(a+b)<<"\n";
    }
    return 0;
}