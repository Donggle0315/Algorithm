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
int find(int);
bool UNION(int,int);
int binarySearch(int);
int n,m,k;
vector<int> card;
int parent[4000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    solve();

    return 0;
}

void init(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        card.push_back(tmp);
    }
    sort(card.begin(),card.end());
    memset(&parent,-1,sizeof(parent));
}

void solve(){
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        int idx=binarySearch(tmp);
        int re=find(idx);
        cout<<card[re]<<"\n";
        UNION(re,re+1);
    }
}

int find(int x){
    if(parent[x]==-1) return x;
    return parent[x]=find(parent[x]);
}

bool UNION(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y) return false;
    if(x<y) swap(x,y);
    parent[y]=x;
    return true;
}

int binarySearch(int x){
    int l=0;
    int r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(card[mid]>x){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return r;
}

