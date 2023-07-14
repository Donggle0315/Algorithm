#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
int sum();
void finish();

int* list;
int n,m;

int main() {
	int i;
	init();
	for (i = 0; i < m; i++) {
		printf("%d\n", sum());
	}
	finish();
	return 0;
}

void finish() {
	free(list);
}

void init() {
	int i;

	scanf("%d %d", &n, &m);
	list = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		if (i == 0) {
			continue;
		}
		list[i] += list[i - 1];
	}
}

int sum() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a == 1) {
		return list[b - 1];
	}
	else {
		return list[b - 1]-list[a-2];
	}
}