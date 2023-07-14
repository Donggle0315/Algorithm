#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j,tmp,num;
	int* list;
	scanf("%d", &num);
	list = (int*)calloc(10001,sizeof(int));
	for (i = 0; i < num; i++) {
		scanf("%d", &tmp);
		list[tmp]++;
	}
	
	for (i = 0; i < 10001; i++) {
		if (list[i] != 0) {
			for(j=0;j<list[i];j++){
				printf("%d\n",i);
			}
		}
	}


	free(list);
	return 0;
}
