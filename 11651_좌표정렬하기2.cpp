#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > list;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        list.push_back({y,x});
    }
    sort(list.begin(),list.end());
    for(int i=0;i<n;i++){
        cout<<list[i].second<<" "<<list[i].first<<"\n";
    }

    return 0;
}