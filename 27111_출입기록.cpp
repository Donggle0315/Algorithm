#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int list[200001]={0};
    int count=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b==1){
            if(list[a]==0){
                list[a]=1;
            }
            else{
                count++;
                list[a]=1;
            }
        }
        else{
            if(list[a]==0){
                count++;
                list[a]=0;
            }
            else{
                list[a]=0;
            }
        }
    }
    for(int i=1;i<200001;i++){
        if(list[i]==1){
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}