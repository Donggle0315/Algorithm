#include <vector>
#include <climits>
#include <iostream>
using namespace std;
 
int n, m;
long long a;
long long maxWait = 0;
vector<long long> v;
long long ans = 1000000000000000001;
 
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a;
        maxWait = max(maxWait, a);
        v.push_back(a);
    }
 
    long long Start = 0;
    long long End = maxWait*m;
 
 
    while(Start<=End){
        long long mid = (Start+End)/2;
        long long tmp = 0;
        for(int i=0; i<v.size(); i++){
            tmp += (mid/v[i]);
        }
 
        if(tmp>=m){
            ans = min(ans, mid);
            End = mid-1;
        }else{
            Start = mid+1;
        }
    }
 
    cout<<ans<<"\n";
    return 0;
}
