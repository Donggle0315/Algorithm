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
void findPokemon();

int n,m;
map<string,int> dogam;
vector<string> vec;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    init();
    findPokemon();

    return 0;
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        vec.push_back(tmp);
        dogam.insert(make_pair(tmp,i));
    }
}

void findPokemon(){
    for(int i=0;i<m;i++){
        string tmp;
        cin>>tmp;
        if('A'<=tmp[0]&&tmp[0]<='Z'){
            cout<<dogam[tmp]<<"\n";
        }
        else{
            cout<<vec[stoi(tmp)-1]<<"\n";
        }
    }
}
