#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec;
    int sum=0;
    int l1,l2;
    for(int i=0;i<9;i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
        sum+=tmp;
    }

    for(int i=0;i<8;i++){
        bool flag=false;
        l1=vec[i];
        for(int j=i+1;j<9;j++){
            l2=vec[j];
            if(l1+l2==sum-100) flag=true;
            if(flag==true) break;    
        }
        if(flag==true) break;
    }

    sort(&vec[0],&vec[9]);
    for(int i=0;i<9;i++){
        if(vec[i]==l1||vec[i]==l2) continue;
        cout<<vec[i]<<endl;
    }


    return 0;
}