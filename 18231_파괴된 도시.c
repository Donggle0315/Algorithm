#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
int destroy();
void print(int);


int** graph;
int* destroyedCity;
int* bomb;
int n, m, k;
int count;

int main() {
	init();
	print(destroy());
	finish();

	return 0;
}

void print(int re) {
	int i;
	if (re == -1) {
		printf("%d", -1);
	}
	else {
		printf("%d\n", count);
		for (i = 1; i <= n; i++) {
			if (bomb[i] == 1) {
				printf("%d ", i);
			}
		}
	}
}

int destroy() {
	int i,j,flag;
	for (i = 1; i <= n; i++) {
		flag = 0;
		if (destroyedCity[i] != 0) {
			for (j = 1; j <= n; j++) {
				if (graph[i][j] == 1 && destroyedCity[j] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				continue;
			}
			bomb[i] = 1;
			destroyedCity[i]++;
			count++;
			for (j = 1; j <= n; j++) {
				if (graph[i][j] == 1 && destroyedCity[j] != 0) {
					destroyedCity[j]++;
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (destroyedCity[i] == 1) {
			return -1;
		}
	}
	return 1;
}



void init() {
	int i, a, b;
	scanf("%d %d", &n, &m);
	graph = (int**)malloc((n + 1) * sizeof(int*));
	for (i = 0; i <= n; i++) {
		graph[i] = (int*)calloc(n + 1, sizeof(int));
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	scanf("%d", &k);
	destroyedCity = (int*)calloc(n+1, sizeof(int));
	bomb = (int*)calloc(n + 1, sizeof(int));
	for (i = 0; i < k; i++) {
		scanf("%d", &a);
		destroyedCity[a] = 1;
	}
	count = 0;
}

void finish() {
	int i;
	for (i = 0; i <= n; i++) {
		free(graph[i]);
	}
	free(graph);
	free(destroyedCity);
	free(bomb);
}