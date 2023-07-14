#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int tc;
    vector<pair<int,int> > vec;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back(make_pair(y,x));
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<tc;i++){
        cout<<vec[i].second<<" "<<vec[i].first<<"\n";
    }
    return 0;
}

