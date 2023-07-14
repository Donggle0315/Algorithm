#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void dfs(int, int);
void deleteCheese();
void play();
int row, col;
int** list;
int** visited;
int cheese;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int main() {

	init();
	play();
	finish();

	return 0;
}

void play() {
	int time = 0;
	int lastCheese = cheese;
	while (cheese > 0) {
		dfs(0, 0);
		lastCheese = cheese;
		deleteCheese();
		time++;
	}
	printf("%d\n", time);
	printf("%d", lastCheese);
}

void deleteCheese() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (list[i][j] == 1 && visited[i][j] == 1) {
				cheese--;
				list[i][j] = 0;
			}
			visited[i][j] = 0;
		}
	}
}

void dfs(int r, int c) {
	visited[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int p = r + dir[i][0];
		int q = c + dir[i][1];
		if (p < 0 || q < 0 || p >= row || q >= col) {
			continue;
		}
		if (visited[p][q] == 1) {
			continue;
		}
		if (list[p][q] == 1) {
			visited[p][q] = 1;
			continue;
		}
		dfs(p, q);
	}
}

void init() {
	scanf("%d %d", &row, &col);
	list = (int**)malloc(row * sizeof(int*));
	visited = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		list[i] = (int*)malloc(col * sizeof(int));
		visited[i] = (int*)calloc(col, sizeof(int));
		for (int j = 0; j < col; j++) {
			scanf("%d", &list[i][j]);
			if (list[i][j] == 1) {
				cheese++;
			}
		}
	}
}

void finish() {
	for (int i = 0; i < row; i++) {
		free(list[i]);
		free(visited[i]);
	}
	free(list);
	free(visited);
}