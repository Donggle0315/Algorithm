#define _CRT_SECURE_NO_WARNINGS
#define INF 9999999999;

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void dijkstra(int);
int getMinIndex();

int n, m;
int* distance;
int* visited;
int** list;
int from, to;

int main() {
	init();
	dijkstra(from);
	printf("%d", distance[to]);
	finish();

	return 0;
}


void init() {
	int i,j,s,e,v;
	scanf("%d %d", &n, &m);
	list = (int**)malloc((n + 1) * sizeof(int*));
	visited = (int*)calloc((n + 1), sizeof(int));
	distance = (int*)calloc((n + 1), sizeof(int));

	for (i = 0; i <= n; i++) {
		list[i] = (int*)calloc(n + 1, sizeof(int));
		for (j = 0; j <= n; j++) {
			list[i][j] = INF;
		}
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &e, &v);
		if (v > list[s][e]) {
			continue;
		}
		list[s][e] = v;
	}
	scanf("%d %d", &from, &to);
}

void finish() {
	int i;
	for (i = 0; i <= n; i++) {
		free(list[i]);
	}
	free(list);
	free(visited);
	free(distance);
}