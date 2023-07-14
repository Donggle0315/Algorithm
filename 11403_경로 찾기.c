#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int n;
	int** map;
	int* visited;
	int** result;
}graph;

void init();
void finish();
void findRoute();
void bfs(int);
void addq(int);
int deleteq();
int empty();
void re_init();


graph* gp;
int* queue;
int front;
int rear;

int main() {
	init();
	findRoute();
	finish();

	return 0;
}

void findRoute() {
	int i,j;
	for (i = 0; i < gp->n; i++) {
		bfs(i);
		re_init();
	}
	for (i = 0; i < gp->n; i++) {
		for (j = 0; j < gp->n; j++) {
			printf("%d ", gp->result[i][j]);
		}
		printf("\n");
	}
}

void bfs(int v) {
	int i;
	int root= v;
	addq(v);
	while (empty() == 0) {
		v = deleteq();
		for (i = 0; i < gp->n; i++) {
			if (gp->map[v][i] == 1 && gp->visited[i] == 0) {
				gp->visited[i] = 1;
				gp->result[root][i] = 1;
				addq(i);
			}
		}
	}
}

void re_init() {
	int i;
	for (i = 0; i < gp->n; i++) {
		gp->visited[i] = 0;
	}
	front = 0;
	rear = 0;
}

void addq(int v) {
	queue[front++] = v;
}

int deleteq() {
	return queue[rear++];
}

int empty() {
	if (front == rear) {
		return 1;
	}
	return 0;
}

void init() {
	int i, j;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d", &gp->n);
	gp->map = (int**)malloc(gp->n * sizeof(int*));
	gp->result = (int**)malloc(gp->n * sizeof(int*));
	gp->visited = (int*)calloc(gp->n, sizeof(int));
	for (i = 0; i < gp->n; i++) {
		gp->map[i] = (int*)malloc(gp->n * sizeof(int));
		gp->result[i] = (int*)calloc(gp->n,sizeof(int));
		for (j = 0; j < gp->n; j++) {
			scanf("%d", &gp->map[i][j]);
		}
	}
	queue = (int*)malloc(gp->n*gp->n * sizeof(int));
	front = 0;
	rear = 0;
}

void finish() {
	int i;
	for (i = 0; i < gp->n; i++) {
		free(gp->map[i]);
		free(gp->result[i]);
	}
	free(gp->result);
	free(gp->map);
	free(gp->visited);
	free(gp);
}