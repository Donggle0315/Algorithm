#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

void init();
void minHeap();

int n;
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    minHeap();

    return 0;
}

void init(){
    cin>>n;
}

void minHeap(){
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==0){
            if(!pq.empty()){
                cout<<-1*pq.top()<<"\n";
                pq.pop();
            }
            else{
                cout<<0<<"\n";
            }
        }
        else{
            pq.push(-1*t);
        }
    }
}
