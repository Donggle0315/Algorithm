#include <iostream>
using namespace std;

void combination(int);
int* result;
int* visited;
int n,m;
int main(){
    cin>>n>>m;
    result=new int[m];
    visited=new int[n+1];

    combination(0);

    return 0;
}

void combination(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            result[depth]=i;
            visited[i]=1;
            combination(depth+1);
            visited[i]=0;
        }
    }
}