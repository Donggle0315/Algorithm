#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#define pii pair<int,int>
#define INF 1e9+7
#define MOD 1004
typedef long long ll;
using namespace std;

void init();
void solve();
int binarySearch(int,int,int);
int n;
vector<int> list;
int lis[1000001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    solve();

    return 0;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        list.push_back(tmp);
    }
}

void solve(){
    int i=1;
    int j=0;
    lis[0]=list[0];
    while(i<n){
        if(lis[j]<list[i]) {
            lis[++j]=list[i];
        }
        else{
            int idx=binarySearch(0,j,list[i]);
            lis[idx]=list[i];
        }
        i++;
    }
    cout<<j+1<<"\n";
    for(int k=0;k<j;k++){
        cout<<lis[k]<<" ";
    }
    cout<<"\n";
}

int binarySearch(int l, int r, int goal){
    int mid;
    while(l<r){
        mid=(l+r)/2;
        if(lis[mid]<goal) l=mid+1;
        else r=mid;
    }
    return r;
}