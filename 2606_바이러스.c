#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void insertEdge(int, int);
int countVirus(int);

int n, m;
int** graph;
int* visit;

int main() {
	init();
	printf("%d", countVirus(0) - 1);
	finish();


	return 0;
}

int countVirus(int idx) {
	int count = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (graph[idx][i] != 0 && visit[i] == 0) {
			count++;
			visit[i] = 1;
			count += countVirus(i);
		}
	}
	return count;
}

void insertEdge(int a, int b) {
	graph[a - 1][b - 1] = 1;
	graph[b - 1][a - 1] = 1;
}

void init() {
	int i,j, a, b;
	scanf("%d ", &n);
	visit = (int*)malloc(n* sizeof(int));
	graph = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		graph[i] = (int*)malloc(n* sizeof(int));
		visit[i] = 0;
		for (j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf(" %d %d", &a, &b);
		insertEdge(a, b);
	}
}

void finish() {
	int i;
	for (i = 0; i < n; i++) {
		free(graph[i]);
	}
	free(graph);
	free(visit);
}