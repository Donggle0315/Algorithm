#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        string str;
        cin>>k>>str;
        for(int j=0;j<str.size();j++){
            for(int p=0;p<k;p++){
                cout<<str[j];
            }
        }
        cout<<endl;
    }

    return 0;
}