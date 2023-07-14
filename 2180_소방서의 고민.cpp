#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void init();
int countMinTime();
bool cmp(pair<int,int>, pair<int,int>);

int n;
vector<pair<int,int> > vec;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    sort(vec.begin(),vec.end(),cmp);
    cout<<countMinTime()<<"\n";
    
    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
    }
}

bool cmp(pair<int,int> v1,pair<int,int> v2){
    if(v1.first==0) return false;
    if(v2.first==0) return true;
    if(v1.second==0&&v2.second==0) return v1.first<v2.first;
    return v1.second*v2.first<v1.first*v2.second;
}

int countMinTime(){
    long long t=0;
    for(int i=0;i<n;i++){
        t+=vec[i].first*t+vec[i].second;
        t%=40000;
    }
    return t;
}