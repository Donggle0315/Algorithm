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




void dijkstra(int start) {
	int i,j, current;
	for (i = 1; i <= n; i++) {
		distance[i] = list[start][i];
	}
	visited[start] = 1;
	for (i = 1; i <= n - 2; i++) {
		current = getMinIndex();
		visited[current] = 1;
		for (j = 1; j <= n; j++) {
			if (visited[j] == 0) {
				if (distance[current] + list[current][j] < distance[j]) {
					distance[j] = distance[current] + list[current][j];
				}
			}
		}
	}
}

int getMinIndex() {
	int min=-1, index = 0,i;
	for (i = 1; i <= n; i++) {
		if (min == -1&&visited[i]==0) {
			min = distance[i];
			index = i;
		}
		if (min > distance[i] && visited[i] == 0) {
			min = distance[i];
			index = i;
		}
	}
	return index;
}