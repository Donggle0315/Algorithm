#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int n;
	int** map;
	int** visited;
}graph;

void init();
//동적 배열 초기화 및 입력 
void finish();
//동적 배열 해제 
void initVisited();
//visited배열 초기화 
int findSafeZone();
//안전 지역을 찾는 함수로 안전지역의 개수 출력 
void dfs(int, int,int);
//해당 층에서의 안전지대 dfs 

int max = 1;//가장 높은 높이 
graph* gp;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상하좌우 방향 

int main() {
	init();
	printf("%d", findSafeZone());
	finish();

	return 0;
}

void dfs(int x, int y, int height) {
	int i,p,q;
	gp->visited[x][y] = 1;
	for (i = 0; i < 4; i++) {
		p = dir[i][0]+x;
		q = dir[i][1] + y;
		if (p < 0 || p >= gp->n) {
			continue;
		}
		if (q < 0 || q >= gp->n) {
			continue;
		}
		if (gp->visited[p][q] == 1) {
			continue;
		}
		if (gp->map[p][q] <= height) {
			continue;
		}
		dfs(p, q, height);
	}
}

int findSafeZone() {
	int i,j,k,count=0, safe = 0;//count는 해당 층의 안전지역 개수를, safe는 count중 최대 크기를 저장 
	for (i = 0; i <= max; i++) {//비가 0층까지 오는 경우부터 가장 높은 max층까지 오는 경우에 대해 
		for (j = 0; j < gp->n; j++) {
			for (k = 0; k < gp->n; k++) {
				if (gp->visited[j][k] == 0 && gp->map[j][k] > i) {//방문하지 않고, 빗물에 잠기지 않은 경우 
					dfs(j, k, i);
					count++;
				}
			}
		}
		if (count > safe) {//해당 층의 안전구역이 max보다 클때 
			safe = count;
		}
		count = 0;
		initVisited();//다음층을 위해 visited배열 초기화 
	}
	return safe;//최대값 반환 
}

void init() {
	int i, j;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d", &gp->n);
	gp->map = (int**)malloc(gp->n * sizeof(int*));
	gp->visited = (int**)malloc(gp->n * sizeof(int*));
	for (i = 0; i < gp->n; i++) {
		gp->map[i] = (int*)malloc(gp->n * sizeof(int));
		gp->visited[i] = (int*)calloc(gp->n, sizeof(int));
		for (j = 0; j < gp->n; j++) {
			scanf("%d", &gp->map[i][j]);
			if (gp->map[i][j] > max) {
				max = gp->map[i][j];
			}
		}
	}
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

}

void initVisited() {
	int i, j;
	for (i = 0; i < gp->n; i++) {
		for (j = 0; j < gp->n; j++) {
			gp->visited[i][j] = 0;
		}
	}
}
