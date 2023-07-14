#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int** paper;
int num;
int white = 0, blue = 0;//white=0, blue=1

void init();
void finish();
void cal(int, int, int);





int main() {
	init();
	cal(0, 0, num);
	printf("%d\n%d", white, blue);
	finish();


	return 0;
}

void cal(int row, int col, int depth) {
	int i, j;
	int flag = 0;
	int k = paper[row][col];
	for (i = 0; i < depth; i++) {
		for (j = 0; j < depth; j++) {
			if (paper[row + i][col + j] != k) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	if (flag == 0) {
		if (k == 0) {
			white++;
		}
		else {
			blue++;
		}
	}
	else {
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				cal(row + i * depth / 2, col + j * depth / 2, depth / 2);
			}
		}
	}



}

void init() {
	int i,j;
	scanf("%d", &num);
	paper = (int**)malloc(num * sizeof(int*));
	for (i = 0; i < num; i++) {
		paper[i] = (int*)malloc(num * sizeof(int));
		for (j = 0; j < num; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
}

void finish() {
	int i;
	for (i = 0; i < num; i++) {
		free(paper[i]);
	}
	free(paper);
}