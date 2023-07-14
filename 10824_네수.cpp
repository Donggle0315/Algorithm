#include <iostream>
using namespace std;

long long makeInt(string);

int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string re1=a+b;
    string re2=c+d;
    long long result=makeInt(re1)+makeInt(re2);
    cout<<result<<endl;
    
    return 0;
}

long long makeInt(string s){
    long long re=0;
    for(int i=0;i<s.size();i++){
        re+=(s[i]-'0');
        re*=10;
    }
    re/=10;
    return re;
}