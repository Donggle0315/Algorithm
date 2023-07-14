#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,num,count=0;
	int* list = (int*)calloc(42, sizeof(int));

	for (i = 0; i < 10; i++) {
		scanf("%d", &num);
		if (list[num % 42] == 0) {
			count++;
			list[num % 42]++;
		}
	}
	printf("%d", count);

	free(list);

	return 0;
}