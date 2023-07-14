#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void quicksort(int, int);

char list[11];
int n;

int main() {
	int i;
	scanf("%s", list);
	n = strlen(list);
	quicksort(0, n - 1);
	for (i = 0; i < n; i++) {
		printf("%d", list[i] - '0');
	}
}

void quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	char x = list[(left + right) / 2];
	char tmp;
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
	if (pl < right) {
		quicksort(pl, right);
	}
	if (left < pr) {
		quicksort(left, pr);
	}
}