#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int n, k;
int max = 0;
int* list;


void init();
void finish();
int findMax(long long, long long);

int main() {
	init();
	printf("%d", findMax(1, max));
	finish();


	return 0;
}

int findMax(long long low, long long high) {
	long long l = low;
	long long h = high;
	long long m;
	int i, tmp = 0;
	int c = 0;
	while (l <= h) {
		m = (l + h) / 2;
		c = 0;
		for (i = 0; i < n; i++) {
			c += list[i] / m;
		}
		if (c >= k) {
			l = m + 1;
			if (tmp < m) {
				tmp = m;
			}
		}
		else {
			h = m - 1;
		}
	}
	return tmp;
}

void init() {
	int i;
	scanf("%d %d", &n, &k);
	list = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		if (list[i] > max) {
			max = list[i];
		}
	}
}

void finish() {
	free(list);
}