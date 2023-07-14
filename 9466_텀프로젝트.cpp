#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

void init();
void dfs(int);

int n,cnt;
int people[100001];
bool isSelected[100001];
bool visited[100001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        init();
        for(int j=1;j<=n;j++){
            if(!visited[j]) dfs(j);
        }
        cout<<n-cnt<<"\n";
    }

    return 0;
}

void init(){
    cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>people[i];
        visited[i]=false;
        isSelected[i]=false;
    }
}

void dfs(int start){
    visited[start]=true;
    int next=people[start];
    if(!visited[next]) dfs(next);
    else if(!isSelected[next]){
        for(int i=next;i!=start;i=people[i]){
            cnt++;
        }
        cnt++;
    }
    isSelected[start]=true;
}
