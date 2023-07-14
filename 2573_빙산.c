#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void re_init();
void finish();
int play();
void dfs(int, int);
void deleteIceBlast();
int isDivided();
void dfs2(int, int);

int n, m;
int** list;
int** visited;
int year;
int iceBlast;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int sum;

int main() {
	init();
	printf("%d",play());
	finish();

	return 0;
}

void dfs2(int r, int c) {
	visited[r][c] = 1;
	sum++;
	for (int i = 0; i < 4; i++) {
		int p = r + dir[i][0];
		int q = c + dir[i][1];
		if (p < 0 || q < 0 || p >= n || q >= m) {
			continue;
		}
		if (list[p][q] == 0) {
			continue;
		}
		if (visited[p][q] == 1) {
			continue;
		}
		dfs2(p, q);
	}
}

int isDivided() {
	int row=-1, col=-1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (list[i][j] > 0) {
				row = i;
				col = j;
				break;
			}
		}
		if (row != -1) {
			break;
		}
	}
	//[row][col] 기준으로 dfs했을 때, 세어진 빙산이 iceBlast보다 적으면 갈라짐]
	re_init();
	dfs2(row, col);
	if (sum != iceBlast) {
		return 1;
	}
	return 0;

}

void deleteIceBlast() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (list[i][j] > 0) {//빙산이면
				if (list[i][j] + visited[i][j] <= 0) {//완전히 없어지는 빙산
					list[i][j] = 0;
					iceBlast--;
				}
				else {
					list[i][j] += visited[i][j];
				}
			}
		}
	}
}

void dfs(int r, int c) {
	visited[r][c]=1;
	for (int i = 0; i < 4; i++) {
		int p = r + dir[i][0];
		int q = c + dir[i][1];
		if (p < 0 || p >= n||q<0||q>=m) {
			continue;
		}
		if (list[p][q] > 0) {//빙산
			visited[p][q]--;
			continue;
		}
		if (list[p][q] == 0 && visited[p][q] != 0) {
			continue;
		}
		dfs(p, q);
	}
}

int play() {
	while (iceBlast!=0) {
		year++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (list[i][j] == 0 && visited[i][j] == 0) {
					dfs(i, j);
				}
			}
		}
		deleteIceBlast();//접하는 만큼 빙산 높이 감소

		if (iceBlast == 0) {
			break;
		}
		if (isDivided() == 1) {//빙산이 분리되면
			return year;
		}
		re_init();
	}

	return 0;//모든 빙산이 녹아버림
}

void init() {
	scanf("%d %d", &n, &m);
	year = 0;
	iceBlast = 0;
	list = (int**)malloc(n * sizeof(int*));
	visited = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		list[i] = (int*)malloc(m * sizeof(int));
		visited[i] = (int*)calloc(m, sizeof(int));
		for (int j = 0; j < m; j++) {
			scanf("%d", &list[i][j]);
			if (list[i][j] != 0) {
				iceBlast++;
			}
		}
	}
}

void re_init() {
	for (int i = 0; i < n; i++) {
		free(visited[i]);
		visited[i] = (int*)calloc(m, sizeof(int));
	}
	sum = 0;
}

void finish() {
	for (int i = 0; i < n; i++) {
		free(list[i]);
		free(visited[i]);
	}
	free(list);
	free(visited);
}