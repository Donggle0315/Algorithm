#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
int findMinDistance();
void mergeSort(int, int);

int n, c;
int* list;
int* temp;


int main() {
	init();
	printf("%d", findMinDistance());
	finish();

	return 0;
}

int findMinDistance() {
	int left = 1;
	int right = list[n - 1] - list[0];
	int distance = 0;
	int re = 0;

	while (left <= right) {
		int middle = (left + right) / 2;
		int start = list[0];
		int current = 1;

		for (int i = 1; i < n; i++) {
			distance = list[i] - start;
			if (middle <= distance) {
				current++;
				start = list[i];
			}
		}

		if (current >= c) {
			re = middle;
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}

	return re;
}

void init() {
	scanf("%d %d", &n, &c);
	list = (int*)malloc(n * sizeof(int));
	temp = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	mergeSort(0, n - 1);
}

void finish() {
	free(list);
	free(temp);
}

void mergeSort(int left, int right) {
	if (left >= right) {
		return;
	}
	int middle = (left + right) / 2;
	mergeSort(left, middle);
	mergeSort(middle + 1, right);

	for (int i = left, l = left, r = middle + 1; l != middle + 1 || r != right + 1; i++) {
		if (r != right + 1 && l <= middle && list[i] < list[r] || r == right + 1) {
			temp[i] = list[l++];
		}
		else {
			temp[i] = list[r++];
		}
	}
	for (int i = left; i <= right; i++) {
		list[i] = temp[i];
	}
}