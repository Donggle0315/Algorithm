#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,x,i;
	int *list;
	scanf("%d %d",&num,&x);
	list=(int*)malloc(sizeof(int)*num);
	for(i=0;i<num;i++){
		scanf("%d ",&list[i]);
	}
	for(i=0;i<num;i++){
		if(list[i]<x){
			printf("%d ",list[i]);
		}
	}	

	return 0;
}
