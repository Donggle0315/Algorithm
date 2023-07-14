#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void printResult();
void findSequence(int);

int* result;
int n, m;

int main() {

	init();
	findSequence(1);
	finish();


	return 0;
}

void init() {
	scanf("%d %d", &n, &m);
	result = (int*)malloc((m + 1) * sizeof(int));
	result[0] = 1;
}

void finish() {
	free(result);
}

void printResult() {
	int i;
	for (i = 1; i <= m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

void findSequence(int depth) {
	int i;
	if (depth == m+1) {
		printResult();
		return;
	}
	for (i = result[depth-1]; i <= n; i++) {
		result[depth] = i;
		findSequence(depth + 1);
	}
}