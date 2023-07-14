#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        int score=1;
        int sum=0;
        cin>>str;
        for(int j=0;j<str.size();j++){
            if(str[j]=='O'){
                sum+=score++;
            }
            else{
                score=1;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}