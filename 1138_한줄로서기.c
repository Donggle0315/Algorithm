//https://www.acmicpc.net/problem/1138
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node* next;
}node;

void init();
void finish();
void makeLine();

int n;
int* list;
node* head;

int main(){
    init();
    makeLine();
    finish();

    return 0;
}

void makeLine(){
    node* cur;
    
    for(int i=n-1;i>=0;i--){
        cur=head;
        node* w=(node*)malloc(sizeof(node));
        w->num=i+1;
        for(int j=0;j<list[i];j++){
            cur=cur->next;
        }
        w->next=cur->next;
        cur->next=w;
    }
    cur=head->next;
    while(cur!=NULL){
        printf("%d ",cur->num);
        cur=cur->next;
    }
}

void init(){
    scanf("%d",&n);
    list=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    head=(node*)malloc(sizeof(node));
    head->num=0;
    head->next=NULL;
}

void finish(){
    free(list);
    node* cur;
    while(head!=NULL){
        cur=head;
        head=head->next;
        free(cur);
    }
}