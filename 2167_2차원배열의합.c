#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
int findListSum();

int** list;
int row,col;
int n;

int main(){
    init();
    for(int i=0;i<n;i++){
        printf("%d\n",findListSum());
    }
    finish();
    return 0;
}

int findListSum(){
    int starti,startj,finishi,finishj;
    scanf("%d %d %d %d",&starti,&startj,&finishi,&finishj);
    int sum=0;
    for(int i=starti-1;i<finishi;i++){
        for(int j=startj-1;j<finishj;j++){
            sum+=list[i][j];
        }
    }
    return sum;
}
void init(){
    scanf("%d %d",&row,&col);
    list=(int**)malloc(row*sizeof(int*));
    for(int i=0;i<row;i++){
        list[i]=(int*)malloc(col*sizeof(int));
        for(int j=0;j<col;j++){
            scanf("%d ",&list[i][j]);
        }
    }
    scanf("%d",&n);
}

void finish(){
    for(int i=0;i<row;i++){
        free(list[i]);
    }
    free(list);
}

