#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    cin>>str;
    vector<int> list;
    for(int i=0;i<str.length();i++){
        list.push_back(str[i]-'0');
    }

    sort(list.begin(),list.end(),greater<int>());

    for(int i=0;i<list.size();i++){
        cout<<list[i];
    }

    return 0;
}