#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void quicksort(int*,int,int);
int partition(int*,int,int);
int isCardInList(int,int,int);

int n,m;
int* nlist;
int* mlist;

int main(){
    init();
    quicksort(nlist,0,n);
    for(int i=0;i<m;i++){
        printf("%d ",isCardInList(mlist[i],0,n));
    }
    finish();

    return 0;
}

void init(){
    scanf("%d",&n);
    nlist=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&nlist[i]);
    }
    scanf("%d",&m);
    mlist=(int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        scanf("%d",&mlist[i]);
    }
}

void finish(){
    free(nlist);
    free(mlist);

}

void quicksort(int* arr,int p,int r){
    if(p<r){
        int pivot=partition(arr,p,r);
        quicksort(arr,p,pivot-1);
        quicksort(arr,pivot+1,r);
    }
}

int partition(int* arr,int p,int r){
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(arr[j]<=x){
            i++;
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
    }
    int tmp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=tmp;
    return i+1;
}

int isCardInList(int num,int left,int right){
    if(left>right) return 0;
    int middle=(left+right)/2;
    if(num==nlist[middle]) return 1;
    else if(num<nlist[middle]) return isCardInList(num,left,middle-1);
    else return isCardInList(num,middle+1,right);
}