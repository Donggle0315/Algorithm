#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int row;
    int col;
}point;

void init();
void finish();
void bfs(int,int);
void addq(int,int);
void deleteq(int*,int*);
int isEmpty();

int testCase,length,startRow,startCol,finishRow,finishCol;
int** list;
point* queue;
int front,rear;
point dir[8]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-2,-1},{-1,-2}};

int main(){
    scanf("%d",&testCase);
    for(int i=0;i<testCase;i++){
        init();
        bfs(startRow,startCol);
        printf("%d\n",list[finishRow][finishCol]-1);
        finish();
    }

    return 0;
}

void bfs(int vi,int vj){
    list[vi][vj]=1;
    addq(vi,vj);

    while(isEmpty()==1){
        int r,c;
        deleteq(&r,&c);
        if(r==finishRow&&c==finishCol){
            break;
        }
        for(int i=0;i<8;i++){
            int p=r+dir[i].row;
            int q=c+dir[i].col;
            if(p<0||p>=length||q<0||q>=length){
                continue;
            }
            if(list[p][q]!=0){
                continue;
            }
            addq(p,q);
            list[p][q]=list[r][c]+1;
        }
    }
}

void init(){
    scanf("%d",&length);
    list=(int**)malloc(length*sizeof(int*));
    for(int i=0;i<length;i++){
        list[i]=(int*)calloc(length,sizeof(int));
    }
    scanf("%d %d",&startRow,&startCol);
    scanf("%d %d",&finishRow,&finishCol);
    queue=(point*)malloc(length*length*sizeof(point));
    front=0;
    rear=0;
}

void finish(){
    for(int i=0;i<length;i++){
        free(list[i]);
    }
    free(list);
    free(queue);
}

void addq(int r,int c){
    queue[front].row=r;
    queue[front++].col=c;
}

void deleteq(int* r, int* c){
    *r=queue[rear].row;
    *c=queue[rear++].col;
}

int isEmpty(){
    if(front==rear){
        return 0;
    }
    return 1;
}
