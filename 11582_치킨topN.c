#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void cal(int, int);
void quicksort(int, int);
void printing(int, int);
void finish();

int n,k;
int* list;

int main() {
	init();
	cal(0, 1);
	printing(0, n - 1);
	finish();
	


	return 0;
}

void quicksort(int left, int right) {
	int tmp;
	int pl = left;
	int pr = right;
	int x = list[(pl + pr) / 2];
	do {
		while (list[pl] < x) {
			pl++;
		}
		while (list[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			tmp = list[pl];
			list[pl] = list[pr];
			list[pr] = tmp;
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

void printing(int a, int b) {
	int i;
	for (i = a; i <= b; i++) {
		printf("%d ", list[i]);
	}
}

void cal(int first, int depth) {
	int i;
	if (depth==k) {
		quicksort(first, first + n/depth - 1);
	}
	else {
		depth *= 2;
		for (i = 0; i < 2;i++) {
			cal(first + i * (n/depth), depth);
		}
	}
	return;
}

void init() {
	int i;
	scanf("%d", &n);
	list = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	scanf("%d", &k);
}

void finish() {
	free(list);
}