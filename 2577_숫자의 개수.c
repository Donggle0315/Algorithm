#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, result=1;
	int* list = (int*)calloc(10,sizeof(int));
	int* num = (int*)malloc(3 * sizeof(int));
	for (i = 0; i < 3; i++) {
		scanf("%d", &num[i]);
		result *= num[i];
	}
	while (result!=0) {
		list[result % 10]++;
		result /= 10;
	}
	for (i = 0; i < 10; i++) {
		printf("%d\n", list[i]);
	}
	
	free(list);
	free(num);

	return 0;
}