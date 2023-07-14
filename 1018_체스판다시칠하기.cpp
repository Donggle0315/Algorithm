#include <iostream>
using namespace std;

void init();
void finish();
int changeMinBox(int,int);

int n,m;
char** board;

int main(){
    init();
    int min=64;
    for(int i=0;i<n-7;i++){
        for(int j=0;j<m-7;j++){
            int k=changeMinBox(i,j);
            if(min>k) min=k;
        }
    }
    cout<<min<<endl;

    finish();
    return 0;
}

void init(){
    cin>>n>>m;
    board=new char* [n];
    for(int i=0;i<n;i++){
        board[i]=new char[m];
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            board[i][j]=str[j];
        }
    }
}

void finish(){
    for(int i=0;i<n;i++){
        delete[] board[i];
    }
    delete[] board;
}

int changeMinBox(int starti,int startj){
    int fb=0, fw=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i+j)%2==0&&board[i+starti][j+startj]=='W'){
                fb++;
            }
            else if((i+j)%2==1&&board[i+starti][j+startj]=='B'){
                fb++;
            }
            if((i+j)%2==0&&board[i+starti][j+startj]=='B'){
                fw++;
            }
            else if((i+j)%2==1&&board[i+starti][j+startj]=='W'){
                fw++;
            }
        }
    }
    return fb<fw?fb:fw;
}