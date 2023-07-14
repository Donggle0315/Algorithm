#include <iostream>
#include <string>
using namespace std;

void init();
void makeSequence(string,int);

int n;
bool flag;
string s;

int main(){
    init();
    makeSequence(s,0);

    return 0;
}

void makeSequence(string str,int depth){
    if(flag==true) return;
    
    for(int i=1;i<=str.size()/2;i++){
        if(str.substr(str.size()-i,i)==str.substr(str.size()-2*i,i)) {
            str="";
            return;
        }
    }
    if(depth==n){
        cout<<str<<endl;
        flag=true;
        return;
    }
    for(int i=0;i<n;i++){
        makeSequence(str+"1",depth+1);
        makeSequence(str+"2",depth+1);
        makeSequence(str+"3",depth+1);
    }
    
}

void init(){
    cin>>n;
    flag=false;
    s="";
}
