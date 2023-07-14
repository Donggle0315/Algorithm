#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void sort(int, int);
int maxSum();


int n;
int* list;


int main() {
	init();
	
	printf("%d", maxSum());
	finish();
	return 0;
}

int maxSum() {
	int sum = 0;
	for (int i = 0;i+1<n; i += 2) {
		if (list[i] <= 0 && list[i + 1] <= 0) {
			list[i] = list[i] * list[i + 1];
			list[i + 1] = 0;
		}
		else {
			break;
		}
	}
	for (int i = n - 1; i-1 >= 0; i -= 2) {
		if (list[i] == 1 || list[i - 1] == 1) {
			continue;
		}
		if (list[i] > 0 && list[i - 1] > 0) {
			list[i] = list[i] * list[i - 1];
			list[i - 1] = 0;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		sum += list[i];
	}
	return sum;
}


void init() {
	scanf("%d", &n);
	list = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	sort(0, n - 1);
}

void finish() {
	free(list);
}

void sort(int left, int right) {
	int  pl = left;
	int pr = right;
	int x = list[(left + right) / 2];
	do {
		while (list[pl] < x) {
			pl++;
		}
		while (x < list[pr]) {
			pr--;
		}
		if (pl <= pr) {
			int t = list[pl];
			list[pl] = list[pr];
			list[pr] = t;
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