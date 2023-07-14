#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int, int);
void quicksort(int, int);
int findAverage(int);
int findMedian(int);
int findMode(int);
int findRange(int);

int* list;

int main() {
	int num,i;

	scanf("%d", &num);
	list = (int*)malloc(num * sizeof(int));
	for (i = 0; i < num; i++) {
		scanf("%d", &list[i]);
	}

	quicksort(0, num - 1);


	printf("%d\n", findAverage(num));
	printf("%d\n", findMedian(num));
	printf("%d\n", findMode(num));
	printf("%d\n", findRange(num));

	free(list);

	return 0;
}

void swap(int a, int b) {
	int tmp = list[a];
	list[a] = list[b];
	list[b] = tmp;
}

void quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	int x = list[(pl + pr) / 2];
	do {
		while (list[pl] < x) {
			pl++;
		}
		while (list[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			swap(pl, pr);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		quicksort(left, pr);
	}
	if (pl < right) {
		quicksort(pl, right);
	}
}

int findAverage(int n) {
	double sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += list[i];
	}
	sum /= n;
	sum = round(sum);
	return (int)sum;
}

int findMedian(int n) {
	return list[((n + 1) / 2)-1];
}

int findMode(int n) {
	int i,count=1,max=0,idx=0;
	int* mode = (int*)calloc(n, sizeof(int));
	if (n == 1) {
		free(mode);
		return list[0];
	}
	for (i = 1; i < n; i++) {
		if (list[i] == list[i - 1]) {
			count++;
		}
		else {
			mode[i - 1] = count;
			count = 1;
		}
		if (i == n - 1) {
			mode[i] = count;
		}
	}
	for (i = 0; i < n; i++) {
		if (mode[i] != 0 && mode[i] > max) {
			max = mode[i];
			idx = i;
			count = 1;
		}
		else if (mode[i] == max) {
			count = 2;
		}
	}
	if (count == 1) {
		free(mode);
		return list[idx];
	}
	if (count == 2) {
		idx = 0;
		for (i = 0; i < n; i++) {
			if (mode[i] == max) {
				idx++;
				if (idx == 2) {
					free(mode);
					return list[i];
				}
			}
	
		}
	}
	return -1;
}

int findRange(int n) {
	return list[n - 1] - list[0];
}