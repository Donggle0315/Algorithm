#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int row;
	int col;
	int** map;
	int** visited;
}graph;

void init();
//동적 할당 및 입력
void deleteSquare();
//좌표를 입력받아 해당 구역 삭제
int countArea();
//구역의 개수와 넓이를 구함
int dfs(int, int);
//한 구역을 dfs
void finish();
//동적 배열 해제
void sort(int, int);
//정렬


int* list;//구역의 넓이를 저장
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//방향을 나타냄
graph* gp;

int main() {
	int i,c;
	init();
	c = countArea();
	sort(0, c - 1);
	printf("%d\n", c);
	for (i = 0; i < c; i++) {
		printf("%d ", list[i]);
	}
	finish();
}

void init() {
	int i,k;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d %d", &gp->row, &gp->col, &k);
	gp->map = (int**)malloc(gp->row * sizeof(int*));
	gp->visited = (int**)malloc(gp->row * sizeof(int*));
	for (i = 0; i < gp->row; i++) {
		gp->map[i] = (int*)calloc(gp->col, sizeof(int));
		gp->visited[i] = (int*)calloc(gp->col, sizeof(int));
	}
	for (i = 0; i < k; i++) {//k번에 대하여 좌표를 입력받아 해당 구역 삭제
		deleteSquare();

	}
	list = (int*)malloc(gp->row * gp->col * sizeof(int));
}

void deleteSquare() {
	int i, j;
	int x1, x2, y1, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	for (i = y1; i < y2; i++) {
		for (j = x1; j < x2; j++) {
			gp->map[i][j] = 1;//입력받은 좌표의 구역을 1로 바꾸어 막혀있음을 알려줌
		}
	}
}

int countArea() {
	int count = 0;
	int i, j;
	for (i = 0; i < gp->row; i++) {
		for (j = 0; j < gp->col; j++) {
			if (gp->visited[i][j] == 0 && gp->map[i][j] == 0) {//접근할 수 있고, 방문하지 않았다면
				list[count++]=dfs(i, j);//dfs 반환값으로 해당 구역의 크기가 나오고, count는 구역의 개수를 나타냄
			}
		}
	}
	return count;//구역의 개수 반환
}

int dfs(int r, int c) {
	int i, p, q;
	int count = 0;//구역의 넓이
	gp->visited[r][c] = 1;
	count++;//넓이 +1
	for (i = 0; i < 4; i++) {
		p = r + dir[i][0];
		q = c + dir[i][1];
		if (p < 0 || p >= gp->row) {//구역 밖
			continue;
		}
		if (q < 0 || q >= gp->col) {//구역 밖
			continue;
		}
		if (gp->visited[p][q] == 1) {//이미 방문했다면
			continue;
		}
		if (gp->map[p][q] == 1) {//접근할 수 없다면
			continue;
		}
		count+=dfs(p, q);//구역의 넓이를 반환받아 추가
	}
	return count;//구역의 넓이 반환
}

void finish() {
	int i;
	for (i = 0; i < gp->row; i++) {
		free(gp->map[i]);
		free(gp->visited[i]);
	}
	free(gp->map);
	free(gp->visited);
	free(gp);
	free(list);
}

void sort(int left, int right) {//퀵정렬 이용
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2];
	int tmp;
	do {
		while (list[pl] < x) {
			pl++;
		}
		while (list[pr] > x) {
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
		sort(left, pr);
	}
	if (pl < right) {
		sort(pl, right);
	}
}