#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void printResult();
void findSequence(int);
void quicksort(int, int);

int* input;
int* result;
int n, m;

int main() {

	init();
	findSequence(0);
	finish();


	return 0;
}

void init() {
	int i;
	scanf("%d %d", &n, &m);
	result = (int*)malloc(m * sizeof(int));
	input = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	quicksort(0, n - 1);
}

void finish() {
	free(result);
	free(input);
}

void quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	int x = input[(left + right) / 2];
	int tmp;
	do {
		while (input[pl] < x) {
			pl++;
		}
		while (input[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			tmp = input[pl];
			input[pl] = input[pr];
			input[pr] = tmp;
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

void printResult() {
	int i;
	for (i = 0; i < m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

void findSequence(int depth) {
	int i;
	if (depth == m) {
		printResult();
		return;
	}
	for (i = 0; i < n; i++) {
		result[depth] = input[i];
		findSequence(depth + 1);
	}
}