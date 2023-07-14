#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int n;
	int** map;
	int** visited;
}graph;

void init();
//���� �迭 �ʱ�ȭ �� �Է� 
void finish();
//���� �迭 ���� 
void initVisited();
//visited�迭 �ʱ�ȭ 
int findSafeZone();
//���� ������ ã�� �Լ��� ���������� ���� ��� 
void dfs(int, int,int);
//�ش� �������� �������� dfs 

int max = 1;//���� ���� ���� 
graph* gp;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿� ���� 

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
	int i,j,k,count=0, safe = 0;//count�� �ش� ���� �������� ������, safe�� count�� �ִ� ũ�⸦ ���� 
	for (i = 0; i <= max; i++) {//�� 0������ ���� ������ ���� ���� max������ ���� ��쿡 ���� 
		for (j = 0; j < gp->n; j++) {
			for (k = 0; k < gp->n; k++) {
				if (gp->visited[j][k] == 0 && gp->map[j][k] > i) {//�湮���� �ʰ�, ������ ����� ���� ��� 
					dfs(j, k, i);
					count++;
				}
			}
		}
		if (count > safe) {//�ش� ���� ���������� max���� Ŭ�� 
			safe = count;
		}
		count = 0;
		initVisited();//�������� ���� visited�迭 �ʱ�ȭ 
	}
	return safe;//�ִ밪 ��ȯ 
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
