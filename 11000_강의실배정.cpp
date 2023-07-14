#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void init();
int countMinClass();

priority_queue<int> pq;
vector<pair<int,int> > vec;
int n;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    sort(vec.begin(),vec.end());
    cout<<countMinClass()<<"\n";
    
    
    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        int s,t;
        cin>>s>>t;
        vec.push_back(make_pair(s,t));
    }
}

int countMinClass(){
    for(int i=0;i<n;i++){
        if(!pq.empty()&&pq.top()>=-vec[i].first) pq.pop();
        pq.push(-vec[i].second); 
    }
    return pq.size();
}