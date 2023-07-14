#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void finish();
void stringNcopy();
void quicksort(char**,int,int);
int partition(char**,int,int);
void printSubstr();

char** substr;
char* str;
int len_str;
char* tmp;

int main(){
    init();
    quicksort(substr,0,len_str-1);
    printSubstr();
    finish();
    return 0;
}

void init(){
    str=(char*)malloc(1001*sizeof(char));
    scanf("%s",str);
    len_str=(int)strlen(str);
    substr=(char**)malloc(len_str*sizeof(char*));
    for(int i=0;i<len_str;i++){
        substr[i]=(char*)malloc(len_str*sizeof(char));
    }
    tmp=(char*)malloc(len_str*sizeof(char));

    stringNcopy();       
}

void finish(){
    for(int i=0;i<len_str;i++){
        free(substr[i]);
    }
    free(str);
    free(substr);
    free(tmp);
}

void printSubstr(){
    for(int i=0;i<len_str;i++){
        printf("%s\n",substr[i]);
    }
}

void stringNcopy(){
    for(int i=0;i<len_str;i++){
        int j;
        for(j=i;j<len_str;j++){
            substr[i][j-i]=str[j];
        }
        substr[i][j-i]='\0';
    }
}

void quicksort(char** arr,int p,int r){
    if(p<r){
        int pivot=partition(arr,p,r);
        quicksort(arr,p,pivot-1);
        quicksort(arr,pivot+1,r);
    }
}

int partition(char** arr,int p,int r){
    int x=r;
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(strcmp(arr[j],arr[x])<=0){
            i++;
            strcpy(tmp,arr[i]);
            strcpy(arr[i],arr[j]);
            strcpy(arr[j],tmp);
        }
    }
    strcpy(tmp,arr[i+1]);
    strcpy(arr[i+1],arr[r]);
    strcpy(arr[r],tmp);
    return i+1;
}
