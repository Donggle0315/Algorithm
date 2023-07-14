#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
}point;

void swap(int, int);
void x_quicksort(int, int);
void y_quicksort(int, int);


point* list;

int main() {
	int num, i, count = 0;

	scanf("%d", &num);
	list = (point*)malloc(num * sizeof(point));
	for (i = 0; i < num; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);
	}

	x_quicksort(0, num - 1);
	for (i = 0; i < num - 1; i++) {
		if (list[i].x != list[i + 1].x) {
			y_quicksort(count, i);
			count = i + 1;
		}
		if (i == num - 2&&list[i].x==list[i+1].x) {
			y_quicksort(count, i + 1);
		}
	}

	for (i = 0; i < num; i++) {
		printf("%d %d\n", list[i].x, list[i].y);
	}

	free(list);


	return 0;
}

void swap(int a, int b) {
	int x, y;
	x = list[a].x;
	y = list[a].y;
	list[a].x = list[b].x;
	list[a].y = list[b].y;
	list[b].x = x;
	list[b].y = y;
}

void x_quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	int a = list[(pl + pr) / 2].x;

	do {
		while (list[pl].x < a) {
			pl++;
		}
		while (list[pr].x > a) {
			pr--;
		}
		if (pl <= pr) {
			swap(pl, pr);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		x_quicksort(left, pr);
	}
	if (pl < right) {
		x_quicksort(pl, right);
	}
}

void y_quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	int a = list[(pl + pr) / 2].y;

	do {
		while (list[pl].y < a) {
			pl++;
		}
		while (list[pr].y > a) {
			pr--;
		}
		if (pl <= pr) {
			swap(pl, pr);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		y_quicksort(left, pr);
	}
	if (pl < right) {
		y_quicksort(pl, right);
	}
}