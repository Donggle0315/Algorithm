#include <iostream>
using namespace std;

typedef struct node{
    string num;
    int strike;
    int ball;
}node;

void init();
void finish();
int isCorrect(int,int,int);

int n;
node* list;

int main(){
    int cnt=0;
    init();
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(i==j) continue;
            for(int k=1;k<10;k++){
                if(i==k || j==k) continue;
                if(isCorrect(i,j,k)==1) cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    finish();
    return 0;
}

int isCorrect(int a,int b,int c){
    for(int i=0;i<n;i++){
        int st=0;
        int ba=0;
        if(a==list[i].num[0]-'0') st++;
        else if(a==list[i].num[1]-'0'||a==list[i].num[2]-'0') ba++;
        if(b==list[i].num[1]-'0') st++;
        else if(b==list[i].num[0]-'0'||b==list[i].num[2]-'0') ba++;
        if(c==list[i].num[2]-'0') st++;
        else if(c==list[i].num[0]-'0'||c==list[i].num[1]-'0') ba++;
        if(list[i].strike!=st||list[i].ball!=ba) return 0;
    }
    return 1;
}

void init(){
    cin>>n;
    list=new node[n];
    for(int i=0;i<n;i++){
        cin>>list[i].num;
        cin>>list[i].strike>>list[i].ball;
    }
}

void finish(){
    delete[] list;
}