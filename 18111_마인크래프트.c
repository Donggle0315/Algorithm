#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
int findMin();
int findMax();
int findTime(int);

int** field;
int* t_list;
int n, m, b;


int main() {
	int min, max, i,t, cost = -1, floor;

	scanf("%d %d %d", &n, &m, &b);
	init();
	min = findMin();
	max = findMax();
	for (i = min; i <= max; i++) {
		t= findTime(i);
		if (t!= -1 && (cost == -1 || cost >=t)) {
			cost = t;
			floor = i;
		}
	}

	printf("%d %d", cost, floor);

	finish(n);
	return 0;
}


void init() {
	int i, j;
	field = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		field[i] = (int*)malloc(m * sizeof(int));
		for (j = 0; j < m; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	t_list = (int*)malloc(257 * sizeof(int));
}

void finish() {
	int i;
	for (i = 0; i < n; i++) {
		free(field[i]);
	}
	free(field);
	free(t_list);
}

int findMin() {
	int i, j;
	int min = 257;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (field[i][j] < min) {
				min = field[i][j];
			}
		}
	}
	return min;
}

int findMax() {
	int i, j;
	int max = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (field[i][j] > max) {
				max = field[i][j];
			}
		}
	}
	return max;
}

int findTime(int height) {
	int i, j;
	int t = 0;
	int count = b;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (field[i][j] < height) {
				count -= height - field[i][j];
				t += height - field[i][j];
			}
			else if (field[i][j] > height) {
				count += field[i][j] - height;
				t += (2 * (field[i][j] - height));
			}
		}
	}
	if (count < 0) {
		return -1;
	}
	else {
		return t;
	}
}