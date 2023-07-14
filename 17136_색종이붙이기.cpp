#include <iostream>
#define WIDTH 10
using namespace std;

void init();
bool isHere(int,int,int);
bool isFinish();
void attachPaper(int,int,int,int);
bool isRange(int,int);
void makePaper(int);

int list[WIDTH][WIDTH];
int paper[6]={5,5,5,5,5,5};
int result=WIDTH*WIDTH;

int main(){
    init();
    makePaper(0);
    if(result==100) cout<<-1<<endl;
    else cout<<result<<endl;

    return 0;
}

void init(){
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<WIDTH;j++){
            cin>>list[i][j];
        }
    }
}

bool isHere(int row,int col,int size){
    for(int i=row;i<row+size;i++){
        for(int j=col;j<col+size;j++){
            if(list[i][j]==0) return false;
        }
    }
    return true;
}

bool isFinish(){
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<WIDTH;j++){
            if(list[i][j]==1) return false;
        }
    }
    return true;
}

void attachPaper(int row,int col,int size,int data){
    for(int i=row;i<row+size;i++){
        for(int j=col;j<col+size;j++){
            list[i][j]=data;
        }
    }
}

bool isRange(int row, int col){
    if(row<=WIDTH&&col<=WIDTH) return true;
    return false;
}

void makePaper(int cnt){
    if(result<cnt) return;
    if(isFinish()){
        if(result>cnt) result=cnt;
        return;
    }

    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<WIDTH;j++){
            if(list[i][j]==1){
                for(int k=5;k>0;k--){
                    if(paper[k]>0&&isHere(i,j,k)&&isRange(i+k,j+k)){
                        paper[k]--;
                        attachPaper(i,j,k,0);
                        makePaper(cnt+1);
                        paper[k]++;
                        attachPaper(i,j,k,1);
                    }
                }
                return;
            }
        }
    }
}