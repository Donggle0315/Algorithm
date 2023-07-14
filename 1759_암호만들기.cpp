#include <iostream>
#include <algorithm>
using namespace std;

void init();
void finish();
void makePassword(string,int,int);

int l,c;
char* alpha;

int main(){
    init();
    makePassword("",0,0);
    finish();

    return 0;
}

void init(){
    cin>>l>>c;
    alpha=new char[c];
    for(int i=0;i<c;i++){
        cin>>alpha[i];
    }
    sort(&alpha[0],&alpha[c]);
}

void finish(){
    delete[] alpha;
}

void makePassword(string str, int depth,int idx){
    if(depth==l){
        int vowel=0;
        for(int i=0;i<c;i++){
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u') vowel++;
        }
        int constant=l-vowel;
        if(constant>=2&&vowel>=1){
            cout<<str<<"\n";
        }
        return;
    }

    for(int i=idx;i<c;i++){
        makePassword(str+alpha[i],depth+1,i+1);
    }
}