#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void init();
int countMaxScore();
bool cmp(pair<int,int>, pair<int,int>);

int n;
int lastday;
priority_queue<pair<int,int> > pq;
int* list;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    init();
    cout<<countMaxScore()<<"\n";
    delete[] list;
    
    return 0;
}

void init(){
    cin>>n;
    lastday=0;
    for(int i=0;i<n;i++){
        int d,w;
        cin>>d>>w;
        pq.push(make_pair(w,d));
        lastday=max(lastday,d);
    }
    list=new int[lastday+1];
    for(int i=0;i<lastday+1;i++){
        list[i]=0;
    }
}

int countMaxScore(){
    for(int i=0;i<n;i++){
        int w=pq.top().first;
        int d=pq.top().second;
        pq.pop();
        for(int j=d;j>0;j--){
            if(list[j]==0){
                list[j]=w;
                break;
            }
        }
    }
    int sum=0;
    for(int i=0;i<=lastday;i++){
        sum+=list[i];
    }
    return sum;
}