#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void init();
int getMaxMeeting();
bool cmp(pair<int,int>,pair<int,int>);
int n;
vector<pair<int,int> > meeting;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    sort(meeting.begin(),meeting.end(),cmp);
    cout<<getMaxMeeting()<<endl;
    
    return 0;
}

int getMaxMeeting(){
    int cnt=0;
    int enable_time=0;
    for(int i=0;i<n;i++){
        if(meeting[i].first>=enable_time){
            cnt++;
            enable_time=meeting[i].second;
        }
    }

    return cnt;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        meeting.push_back(make_pair(start,end));
    }    
}

bool cmp(pair<int,int> v1, pair<int, int> v2){
    if(v1.second==v2.second){
        return v1.first<v2.first;
    }
    return v1.second<v2.second;
}