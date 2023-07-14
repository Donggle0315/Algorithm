#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num, i, a, b=0;
	int* list;

	scanf("%d", &num);
	list = (int*)malloc(num * sizeof(int));
	for (i = 0; i < num; i++) {
		scanf("%d", &list[i]);
	}
	scanf("%d", &a);
	for (i = 0; i < num; i++) {
		if (list[i] == a) {
			b++;
		}
	}
	printf("%d", b);
	
	free(list);

	return 0;
}