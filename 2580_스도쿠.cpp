#include <iostream>
#include <vector>
#define WIDTH 9
using namespace std;

void init();
void makeSdoku(int);
bool isHere(int,int,int);

vector <pair<int,int> > vec;
int list[WIDTH][WIDTH];
int cnt;
bool flag;

int main(){
    init();
    makeSdoku(0);

    return 0;
}

void init(){
    cnt=0;
    flag=false;
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<WIDTH;j++){
            cin>>list[i][j];
            if(list[i][j]==0){
                vec.push_back(make_pair(i,j));
                cnt++;
            }
        }
    }
}

void makeSdoku(int depth){
    if(flag) return;
    if(depth==cnt){
        for(int i=0;i<WIDTH;i++){
            for(int j=0;j<WIDTH;j++){
                cout<<list[i][j]<<" ";
            }
            cout<<"\n";
        }
        flag=true;
        return;
    }
    int row=vec[depth].first;
    int col=vec[depth].second;
    for(int i=1;i<=9;i++){
        if(isHere(row,col,i)){
            list[row][col]=i;
            makeSdoku(depth+1);
            list[row][col]=0;
        }
    }
}

bool isHere(int row,int col,int data){
    for(int i=0;i<WIDTH;i++){
        if(list[i][col]==data||list[row][i]==data) return false;
        for(int p=0;p<3;p++){
            for(int q=0;q<3;q++){
                if(list[row-row%3+p][col-col%3+q]==data) return false;
            }
        }
    }
    return true;
}
