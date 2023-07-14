#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void quicksort(int*,int, int);
int selectTile();
int filla();
int fillb();

int n, a, b;//a : 2*1 b:2*2;
int alist[2000];
int blist[2000];
int tile[2000];

int main() {

	init();
	printf("%d", selectTile());

	return 0;
}

int selectTile() {
	int max = 0;
	int i = 0;
	if (n % 2 == 1) {
		max += alist[--a];
		i++;
	}
	while (i < n) {
		if (a <= 1) {
			max+=fillb();
			i += 2;
		}
		else if (b <= 0) {
			max += filla();
			i += 2;
		}
		else {
			if (alist[a - 1] + alist[a - 2] > blist[b - 1]) {
				max += filla();
				i += 2;
			}
			else {
				max += fillb();
				i += 2;
			}
		}
	}
	return max;
}

int filla() {
	return alist[--a] + alist[--a];
}

int fillb() {
	return blist[--b];
}

void init() {
	int i;
	scanf("%d %d %d", &n, &a, &b);
	for (i = 0; i < a; i++) {
		scanf("%d", &alist[i]);
	}
	for (i = 0; i < b; i++) {
		scanf("%d", &blist[i]);
	}
	quicksort(alist, 0, a - 1);//오름차순
	quicksort(blist, 0, b - 1);

}

void quicksort(int* list, int left, int right) {
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
	if (left < pr) {
		quicksort(list, left, pr);
	}
	if (pl < right) {
		quicksort(list, pl, right);
	}
}