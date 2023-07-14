#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void fillBoard(int,int);
int findArea();

int n;
int **list;

int main(){
    init();
    for(int i=0;i<n;i++){
        int row,col;
        scanf("%d %d",&row,&col);
        fillBoard(row,col);
    }
    printf("%d",findArea());
    finish();
    return 0;
}

int findArea(){
    int count=0;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(list[i][j]==1){
                count++;
            }
        }
    }
    return count;
}
void fillBoard(int row, int col){
    for(int i=row;i<row+10;i++){
        if(i>=101) break;
        for(int j=col;j<col+10;j++){
            if(j>=101) break;
            list[i][j]=1;
        }
    }
}

void init(){
    scanf("%d",&n);
    list=(int**)malloc(101*sizeof(int*));
    for(int i=0;i<101;i++){
        list[i]=(int*)calloc(101,sizeof(int));
    }
}

void finish(){
    for(int i=0;i<101;i++){
        free(list[i]);
    }
    free(list);

}
