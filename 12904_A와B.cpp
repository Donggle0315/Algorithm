#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void addA();
void reverse_addB();

char s[1001];
char t[1001];
int slen, tlen;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin>>s;
    cin>>t;
    slen=strlen(s);
    tlen=strlen(t);

    while(slen!=tlen){
        if(t[tlen-1]=='A') addA();
        else reverse_addB();
    }    

    if(strncmp(s,t,slen)==0) cout<<"1\n";
    else cout<<"0\n";
    
    return 0;
}

void addA(){
    tlen--;
}

void reverse_addB(){
    tlen--;
    for(int i=0;i<tlen/2;i++){
        char tmp=t[i];
        t[i]=t[tlen-i-1];
        t[tlen-i-1]=tmp;
    }
}