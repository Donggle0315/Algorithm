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

struct tmp{
    int data;
    int oper;
    tmp(int _data,int _oper) : data(_data), oper(_oper) {}
    bool operator<(const tmp tg) const{
        if(data==tg.data) return oper>tg.oper;
        return data>tg.data;
    }
    void print(){
        cout<<data*oper<<"\n";
    }
};

void init();
bool cmp(pair<int,int>,pair<int,int>);
void absHeap();

int n;
priority_queue<tmp> pq;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    absHeap();

    return 0;
}

void init(){
    cin>>n;
}

void absHeap(){
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==0){
            if(!pq.empty()){
                tmp temp=pq.top();
                pq.pop();
                temp.print();
            }
            else{
                cout<<0<<"\n";
            }
        }
        else{
            if(t<0){
                pq.push(tmp(abs(t),-1));
            }
            else{
                pq.push(tmp(t,1));
            }
        }
    }
}
