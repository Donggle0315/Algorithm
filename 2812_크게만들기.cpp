#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

void init();
void makeBiggerNum();

int n,k;
stack<int> st;
vector<char> vec;
string tmp;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int cnt=0;
    init();
    makeBiggerNum();
    while(!st.empty()){
        vec.push_back(st.top());
        st.pop();
    }
    for(int i=vec.size()-1;i>=0;i--){
        cout<<vec[i];
    }
    cout<<"\n";
    
    return 0;
}

void init(){
    cin>>n>>k;
    cin>>tmp;
}

void makeBiggerNum(){
    for(int i=0;i<n;i++){
        while(!st.empty()&&k!=0&&st.top()<tmp[i]){
            st.pop();
            k--;
        }
        st.push(tmp[i]);
    }
    for(;k>0;k--){
        st.pop();
    }
}