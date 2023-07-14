#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int n;
	int** map;
	int** visited;
}graph;

void init();
//동적 배열 할당 및 입력
void finish();
//동적 해제
int countDanji();
//단지의 개수와 단지내 집의 수를 저장하고 단지 개수 반환
int dfs(int, int);
//단지를 dfs로 탐색하여 단지내 집의 수 반환
void sort(int, int);
//정렬

graph* gp;
int* list;//단지내 집의 수 저장
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//상하좌우 방향

int main() {
	int i, c;
	init();
	c = countDanji();
	sort(0, c - 1);
	printf("%d\n", c);
	for (i = 0; i < c; i++) {
		printf("%d\n", list[i]);
	}
	finish();


	return 0;
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

int dfs(int x, int y) {
	int count = 0;//단지 내 아파트 개수
	int i,p,q;
	gp->visited[x][y] = 1;
	count++;
	for (i = 0; i < 4; i++) {//상하좌우 방향에 대해서
		p = x + dir[i][0];
		q = y + dir[i][1];
		if (p < 0 || p >= gp->n) {//범위 밖
			continue;
		}
		if (q < 0 || q >= gp->n) {//범위 밖
			continue;
		}
		if (gp->map[p][q] == 0) {//단지가 아니라면
			continue;
		}
		if (gp->visited[p][q] == 1) {//이미 방문 했다면
			continue;
		}
		count += dfs(p, q);
	}
	return count;
}

int countDanji() {
	int count = 0;
	int i, j;
	for (i = 0; i < gp->n; i++) {
		for (j = 0; j < gp->n; j++) {
			if (gp->map[i][j] == 1 && gp->visited[i][j] == 0) {//아파트가 있고 방문하지 않았다면
				list[count++] = dfs(i, j);
			}
		}
	}
	return count;
}

void init() {
	int i,j;
	char* str;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d", &gp->n);
	str = (char*)malloc((gp->n + 1) * sizeof(char));
	gp->map = (int**)malloc(gp->n * sizeof(int*));
	gp->visited = (int**)malloc(gp->n * sizeof(int*));
	for (i = 0; i < gp->n; i++) {
		scanf("%s", str);
		gp->map[i] = (int*)malloc(gp->n * sizeof(int));
		gp->visited[i] = (int*)calloc(gp->n , sizeof(int));
		for (j = 0; j < gp->n; j++) {
			gp->map[i][j] = str[j]-'0';
		}
	}
	list = (int*)malloc(gp->n*gp->n * sizeof(int));
	free(str);
}

void finish() {
	int i;
	for (i = 0; i < gp->n; i++) {
		free(gp->map[i]);
		free(gp->visited[i]);
	}
	free(gp->map);
	free(gp->visited);
	free(gp);
	free(list);
}