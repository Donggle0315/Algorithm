#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int i,j, num, cut,tmp,max;
	int* list;

	scanf("%d %d", &num, &cut);
	list = (int*)malloc(num * sizeof(int));
	for (i = 0; i < num; i++) {
		scanf("%d", &list[i]);
	}
	for (i = 0; i < num - 1;i++) {
		max = i;
		for (j = i; j < num; j++) {
			if (list[j] > list[max]) {
				max = j;
			}
		}
		tmp = list[i];
		list[i] = list[max];
		list[max] = tmp;
	}
	printf("%d", list[cut-1]);
	free(list);
	return 0;

}