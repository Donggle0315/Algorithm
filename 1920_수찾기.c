#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* nlist;
int* mlist;
int n, m;

void init();
void finish();
void swap(int, int);
void quick(int, int);
int bin_search(int);

int main() {
	int i,result;
	init();

	quick(0, n - 1);
	for (i = 0; i < m; i++) {
		result = bin_search(mlist[i]);
		if (result == -1) {
			printf("%d\n", 0);
		}
		else {
			printf("%d\n", 1);
		}
	}

	finish();
	return 0;
}

int bin_search(int key) {
	int pl = 0;
	int pr = n - 1;
	int pc;
	do {
		pc = (pl + pr) / 2;
		if (nlist[pc] == key) {
			return pc;
		}
		else if (nlist[pc] < key) {
			pl = pc + 1;
		}
		else {
			pr = pc - 1;
		}
	} while (pl <= pr);
	return -1;
}

void quick(int left, int right) {
	int pl = left;
	int pr = right;
	int x = nlist[(pl + pr) / 2];
	do {
		while (nlist[pl] < x) {
			pl++;
		}
		while (nlist[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			swap(pl, pr);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		quick(left, pr);
	}
	if (pl < right) {
		quick(pl, right);
	}
}

void swap(int a, int b) {
	int tmp = nlist[a];
	nlist[a] =nlist[b];
	nlist[b] = tmp;
}

void init() {
	int i;
	scanf("%d", &n);
	nlist = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &nlist[i]);
	}
	scanf("%d", &m);
	mlist = (int*)malloc(m * sizeof(int));
	for (i = 0; i < m; i++) {
		scanf("%d", &mlist[i]);
	}
}

void finish() {
	free(nlist);
	free(mlist);
}