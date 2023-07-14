#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void sort(int, int);
int lower(int*, int);
int upper(int*, int);
void cal();

int n,m;
int* list;



int main() {
	init();
	sort(0,n-1);
	cal();
	finish();

	return 0;
}

void cal() {
	int i,t;
	for (i = 0; i < m; i++) {
		scanf("%d", &t);
		printf("%d ", upper(list, t) - lower(list, t));
	}
}

int lower(int* arr, int key) {
	int l = 0;
	int h = n;
	int m;
	while (l < h) {
		m = (l + h) / 2;
		if (key <= arr[m]) {
			h = m;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}

int upper(int* arr, int key) {
	int l = 0;
	int h = n;
	int m;
	while (l < h) {
		m = (l + h) / 2;
		if (key < arr[m]) {
			h = m;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}


void init() {
	int i;
	scanf("%d", &n);
	list = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	scanf("%d", &m);
}

void finish() {
	free(list);
}

void sort(int left, int right) {
	int tmp;
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2];
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
		sort(left, pr);
	}
	if (pl < right) {
		sort(pl, right);
	}
}