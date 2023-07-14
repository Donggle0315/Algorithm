#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int init();

int n, k;
int* list;

int main() {
	printf("%d", init());


	return 0;
}

int init() {
	int i, max;
	scanf("%d %d", &n, &k);
	list = (int*)malloc(n * sizeof(int));
	scanf("%d", &list[0]);
	for (i = 1; i < n; i++) {
		scanf("%d", &list[i]);
		list[i] += list[i - 1];
	}
	max = list[k - 1];
	for (i = k; i < n; i++) {
		if (list[i] - list[i - k] > max) {
			max = list[i] - list[i - k];
		}
	}
	free(list);
	return max;
}