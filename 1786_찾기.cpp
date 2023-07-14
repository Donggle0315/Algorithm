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
void pmatch(string,string);
void fail(string);

string n,m;
int failure[1000001];
vector<int> vec;
int ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    fail(m);
    pmatch(n,m);
    cout<<ans<<"\n";
    for(int i=0;i<ans;i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

void init(){
    getline(cin,n);
    getline(cin,m);
    ans=0;
}

void pmatch(string str, string pat){
    int j=0;
    int lens=str.size();
    int lenp=pat.size();
    for(int i=0;i<lens;i++){
        while(i<lens&&j<lenp){
            if(str[i]==pat[j]){
                if(j==lenp-1){
                    vec.push_back(i-lenp+2);
                    j=failure[j];
                    ans++;
                }
                i++;
                j++;
            }
            else if(j==0) i++;
            else {
                j=failure[j-1]+1;
            }
        }
        
    }
}

void fail(string pat){
    int i,k=pat.size();
    failure[0]=-1;
    for(int j=1;j<k;j++){
        i=failure[j-1];
        while(pat[j]!=pat[i+1]&&(i>=0)){
            i=failure[i];
        }
        if(pat[j]==pat[i+1]) failure[j]=i+1;
        else failure[j]=-1;
    }
}