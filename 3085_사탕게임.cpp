#include <iostream>
using namespace std;

void init();
void finish();
int maxCandy();

int n;
char** list;

int main(){
    init();
    cout<<maxCandy()<<endl;
    finish();
    return 0;
}

int maxCandy(){
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k=0;
            for(int p=i;p<n;p++){
                if(list[i][j]==list[p][j]) k++;
                else break;
            }
            for(int p=i-1;p>=0;p--){
                if(list[i][j]==list[p][j]) k++;
                else break;
            }
            if(k>max) max=k;
            k=0;
            for(int p=j;p<n;p++){
                if(list[i][j]==list[i][p]) k++;
                else break;
            }
            for(int p=j-1;p>=0;p--){
                if(list[i][j]==list[i][p]) k++;
                else break;
            }
            if(k>max) max=k;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=n-1&&list[i][j]!=list[i][j+1]){
                char tmp=list[i][j];
                list[i][j]=list[i][j+1];
                list[i][j+1]=tmp;
                int k=0;
                for(int p=i;p>=0;p--){
                    if(list[i][j]==list[p][j]) k++;
                    else break;
                }
                for(int p=i+1;p<n;p++){
                    if(list[i][j]==list[p][j]) k++;
                    else break;
                }
                if(max<k) max=k;
                k=0;
                for(int p=j;p>=0;p--){
                    if(list[i][j]==list[i][p]) k++;
                    else break;
                }
                for(int p=j+1;p<n;p++){
                    if(list[i][j]==list[i][p]) k++;
                    else break;
                }
                if(max<k) max=k;
                k=0;
                for(int p=i;p>=0;p--){
                    if(list[i][j+1]==list[p][j+1]) k++;
                    else break;
                }
                for(int p=i+1;p<n;p++){
                    if(list[i][j+1]==list[p][j+1]) k++;
                    else break;
                }
                if(max<k) max=k;
                k=0;
                for(int p=j+1;p>=0;p--){
                    if(list[i][j+1]==list[i][p]) k++;
                    else break;
                }
                for(int p=j+2;p<n;p++){
                    if(list[i][j+1]==list[i][p]) k++;
                    else break;
                }
                if(max<k) max=k;
                tmp=list[i][j];
                list[i][j]=list[i][j+1];
                list[i][j+1]=tmp;
            }
            if(i!=n-1&&list[i][j]!=list[i+1][j]){
                char tmp=list[i][j];
                list[i][j]=list[i+1][j];
                list[i+1][j]=tmp;
                int k=0;
                for(int p=i;p>=0;p--){
                    if(list[i][j]==list[p][j]) k++;
                    else break;
                }
                for(int p=i+1;p<n;p++){
                    if(list[i][j]==list[p][j]) k++;
                    else break;
                }
                if(max<k) max=k;
                k=0;
                for(int p=j;p>=0;p--){
                    if(list[i][j]==list[i][p]) k++;
                    else break;
                }
                for(int p=j+1;p<n;p++){
                    if(list[i][j]==list[i][p]) k++;
                    else break;
                }
                if(max<k) max=k;
                k=0;
                for(int p=j;p>=0;p--){
                    if(list[i+1][j]==list[i+1][p]) k++;
                    else break;
                }
                for(int p=j+1;p<n;p++){
                    if(list[i+1][j]==list[i+1][p]) k++;
                    else break;
                }
                if(max<k) max=k;
                k=0;
                for(int p=i+1;p>=0;p--){
                    if(list[i+1][j]==list[p][j]) k++;
                    else break;
                }
                for(int p=i+2;p<n;p++){
                    if(list[i+1][j]==list[p][j]) k++;
                    else break;
                }
                if(max<k) max=k;
                tmp=list[i][j];
                list[i][j]=list[i+1][j];
                list[i+1][j]=tmp;
            }
        }
    }
    return max;
}

void init(){
    cin>>n;
    list=new char*[n];
    for(int i=0;i<n;i++){
        list[i]=new char[n];
        string str;
        cin>>str;
        for(int j=0;j<n;j++){
            list[i][j]=str[j];
        }
    }
}

void finish(){
    for(int i=0;i<n;i++){
        delete[] list[i];
    }
    delete[] list;
}