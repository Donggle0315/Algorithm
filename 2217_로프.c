#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
void quicksort(int, int);
int findMax();

int n;
int list[100000];

int main() {
	init();
	printf("%d", findMax());

	return 0;
}

int findMax() {
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += list[i];
		
		if (max < list[i] * (i + 1)) {
			max = list[i] * (i + 1);
		}
	}
	return max;
}


void init() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	quicksort(0, n - 1);
}

void quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2];
	int tmp;
	do {
		while (list[pl] > x) {
			pl++;
		}
		while (x > list[pr]) {
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
	if(left<pr){
		quicksort(left, pr);
	}
	if (pl < right) {
		quicksort(pl, right);
	}
}