#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void quicksort(int*,int, int, int);
void finish();
void printMin();

int n;
int* lista;
int* listb;

int main() {
	init();
	printMin();
	finish();


	return 0;
}

void init() {
	scanf("%d", &n);
	lista = (int*)malloc(n * sizeof(int));
	listb = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &lista[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &listb[i]);
	}
	quicksort(lista, 0, n - 1, 1);
	quicksort(listb, 0, n - 1, -1);
}

void finish() {
	free(lista);
	free(listb);
}

void quicksort(int* list, int left, int right, int flag) {
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2];
	int tmp;
	if (flag == 1) {
		do {
			while (list[pl] < x) {
				pl++;
			}
			while (x < list[pr]) {
				pr--;
			}
			if (pl <= pr) {
				tmp = list[pl];
				list[pl]=list[pr];
				list[pr] = tmp;
				pl++;
				pr--;
			}
		} while (pl <= pr);
	}
	else if (flag == -1) {
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
	}
	if (pl < right) {
		quicksort(list, pl, right, flag);
	}
	if (left < pr) {
		quicksort(list, left, pr, flag);
	}
}

void printMin() {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += (lista[i] * listb[i]);
	}
	printf("%d", sum);
}