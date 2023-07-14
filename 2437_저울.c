#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void init();
void quicksort(int, int);
int isSolve();
void finish();

int n;
int* list;


int main() {
	init();
	
	printf("%d", isSolve());
	finish();

	return 0;
}



int isSolve() {
	int sum = 0;
	int i,nStart,nFinish;
	int finish = list[0];
	if (n == 1) {
		if (list[0] == 1) {
			return 2;
		}
		else {
			return 1;
		}
	}
	if (list[0] != 1) {
		return 1;
	}
	for (i = 1; i < n; i++) {
		nStart = list[i];
		nFinish = list[i] + finish;
		if (finish+1 < nStart) {
			return finish + 1;
		}
		finish = nFinish;
	}
	for (i = 0; i < n; i++) {
		sum += list[i];
	}
	return sum + 1;
}

void init() {
	int i;
	scanf("%d", &n);
	list = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	quicksort(0, n - 1);
}

void finish() {
	free(list);
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
			tmp = list[pl];
			list[pl] = list[pr];
			list[pr] = tmp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (pl < right) {
		quicksort(pl, right);
	}
	if (left < pr) {
		quicksort(left, pr);
	}
}