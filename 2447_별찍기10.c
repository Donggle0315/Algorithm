#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
void printstar(int, int, int);
void blank(int,int,int);
void printing();
void finish();

int n;
int** board;//0이면 별, 1이면 공백

int main() {
	init();
	printstar(0, 0, n);
	printing();
	finish();


	return 0;
}

void finish() {
	int i;
	for (i = 0; i < n; i++) {
		free(board[i]);
	}
	free(board);
}

void printing() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void printstar(int row, int col, int depth) {
	int i, j;
	if (depth == 1) {
		return;
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				blank(row+i*depth/3,col+j*depth/3,depth/3);
			}
			else {
				printstar(row + i * depth / 3, col + j * depth / 3, depth / 3);
			}
		}
	}
}

void blank(int row,int col,int depth) {
	int i, j;
	for (i = 0; i < depth; i++) {
		for (j = 0; j < depth; j++) {
			board[row + i][col + j] = 1;
		}
	}
}

void init() {
	int i;
	scanf("%d", &n);
	board = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		board[i] = (int*)calloc(n, sizeof(int));
	}
}