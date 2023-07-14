#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compareWith(string,string);

int main(){
    int n;
    cin>>n;
    vector<string> list;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(find(list.begin(),list.end(),str)==list.end()){
            list.push_back(str);
        }
    }
    sort(list.begin(),list.end(),compareWith);
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<"\n";
    }

    return 0;
}

bool compareWith(string a, string b){
    if(a.length()==b.length()){
        return a<b;
    }
    return a.length()<b.length();
}