#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void quicksort(int, int);
void printing();
void finish();

int n;
int* list;

int main() {
	init();
	quicksort(0, n - 1);
	printing();
	finish();

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	list = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
}

void quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2];
	int tmp;
	do {
		while (list[pl] < x) {
			pl++;
		}
		while (x < list[pr]) {
			pr--;
		}
		if (pl <= pr) {
			tmp = list[pr];
			list[pr] = list[pl];
			list[pl] = tmp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		quicksort(left, pr);
	}
	if (pl < right) {
		quicksort(pl, right);
	}
}

void printing() {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
}

void finish() {
	free(list);
}