#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void countBlock();
int findMax();

int n, k;
int num = 0;
int* list;
int* count;

int main() {
	int route;
	int i;
	init();
	countBlock();
	route = findMax();
	printf("%d", route);
	finish();

	return 0;
}

int findMax() {
	int i;
	int max = 0;
	for (i = 0; i < num; i++) {
		if (count[i] > max) {
			max = count[i];
		}
	}
	for (i = 0; i < num-1; i++) {
		if (count[i] + count[i + 1] > max) {
			max = count[i] + count[i + 1];
		}
	}
	return max;
}

void countBlock() {
	int i;
	int c = 1;
	for (i = 0; i <n-1; i++) {
		if (list[i] <= k) {
			c++;
		}
		else {
			count[num++] = c;
			c = 1;
		}
	}
	count[num++] = c;
}

void init() {
	int i;
	scanf("%d %d", &n, &k);
	list = (int*)malloc((n - 1) * sizeof(int));
	for (i = 0; i < n - 1; i++) {
		scanf("%d", &list[i]);
	}
	count = (int*)calloc(n, sizeof(int));
}

void finish() {
	free(list);
	free(count);
}