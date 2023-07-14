#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin>>str;
    int list[26]={0};

    for(int i=0;i<str.size();i++){
        if('a'<=str[i]&&str[i]<='z'){
            list[str[i]-'a']++;
        }
        else{
            list[str[i]-'A']++;
        }
    }
    int max=0,flag=0;
    for(int i=1;i<26;i++){
        if(list[i]>list[max]){
            max=i;
            flag=0;
        }
        else if(list[i]==list[max]){
            flag=1;
        }
    }
    if(flag==1){
        cout<<"?"<<endl;
    }
    else{
        cout<<(char)('A'+max)<<endl;
    }

    return 0;
}