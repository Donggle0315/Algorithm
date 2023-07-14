#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>;

int main() {
	int num, i, j, tmp, max = 0, sum = 0, count;
	int* list;
	scanf("%d", &num);
	list = (int*)malloc(num * sizeof(int));
	for (i = 0; i < num; i++) {
		scanf("%d", &list[i]);
	}

	for (i = 0; i < num - 1; i++) {
		max = i;
		for (j = i+1; j < num; j++) {
			if (list[max] < list[j]) {
				max = j;
			}
		}
		tmp = list[i];
		list[i] = list[max];
		list[max] = tmp;
	}
	for (i = 1; i <= num; i++) {
		sum += list[i-1] * i;
	}

	printf("%d", sum);

	return 0;
}