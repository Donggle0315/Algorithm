#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    int word = 0;
    if(str.empty()){
        cout << "0";
        return 0;
    }

    word = 1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ')
            word++;
    }
    if(str[0] == ' ')
        word--;
    if(str[str.length()-1] == ' ')
        word--;

    cout << word;
    return 0;
}