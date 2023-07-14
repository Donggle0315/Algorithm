#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void re_init();
void finish();
void dfs(int,int);
void deleteCheese();
void play();

int n, m;
int** list;
int** visited;
int cheese;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int time;

int main() {
	init();
	play();
	finish();

	return 0;
}

void deleteCheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (list[i][j] == 1 && visited[i][j] <= -2) {
				cheese--;
				list[i][j] = 0;
			}
		}
	}
}

void dfs(int r, int c) {
	visited[r][c] = 1;

	for(int i=0;i<4;i++){
		int p = r + dir[i][0];
		int q = c + dir[i][1];
		if (p < 0 || p >= n || q < 0 || q >= m) {
			continue;
		}
		if (list[p][q] == 1) {
			visited[p][q]--;
			continue;
		}
		if (visited[p][q] != 0) {
			continue;
		}
		dfs(p, q);
	}
}

void play() {
	while (cheese > 0) {
		dfs(0, 0);
		deleteCheese();
		time++;
		re_init();
	}
	printf("%d", time);
}


void init() {
	scanf("%d %d", &n, &m);
	list = (int**)malloc(n * sizeof(int*));
	visited = (int**)malloc(n * sizeof(int*));
	cheese = 0;
	time = 0;
	for (int i = 0; i < n; i++) {
		list[i] = (int*)malloc(m * sizeof(int));
		visited[i] = (int*)calloc(m,sizeof(int));
		for (int j = 0; j < m; j++) {
			scanf("%d", &list[i][j]);
			if (list[i][j] == 1) {
				cheese++;
			}
		}
	}
}

void re_init() {
	for (int i = 0; i < n; i++) {
		free(visited[i]);
	}
	free(visited);
	visited = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		visited[i] = (int*)calloc(m, sizeof(int));
	}
}

void finish() {
	for (int i = 0; i < n; i++) {
		free(list[i]);
		free(visited[i]);
	}
	free(list);
	free(visited);
}