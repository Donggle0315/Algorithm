#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec;
    int sum=0;
    for(int i=0;i<5;i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
        sum+=tmp;
    }
    sort(&vec[0],&vec[5]);
    cout<<sum/5<<endl;
    cout<<vec[2]<<endl;

    return 0;
}