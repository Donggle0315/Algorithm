#define _CRT_SECURE_NO_WARNINGS
#define INF 9876543

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void dijkstra(int,int**,int*,int*);
int getMinIndex(int*, int*);
int findMinRoute();

int n, e;
int** arr;
int start, end, value;
int m1, m2;
int* d1;
int* v1;
int* d2;
int* v2;
int* d3;
int* v3;

int main() {
	init();
	dijkstra(1, arr, d1, v1);//1에서의 최단거리
	dijkstra(n, arr, d2, v2);//n까지의 최단거리
	dijkstra(m1, arr, d3, v3);//경유지1에서의 최단거리
	printf("%d", findMinRoute());//1-m1-m2-n의 최단거리를 반환
	finish();

	return 0;
}

int findMinRoute() {
	if (d3[m2] >= INF) {//경로 X
		return -1;
	}
	if ((m1 == 1 && m2 == n) || (m1 == n && m2 == 1)) {
		return d1[n];//경로 1-n
	}
	if (m1 == 1 || m1 == n) {//경로 1-m2-n
		return d1[m2] + d2[m2];
	}
	if (m2 == 1 || m2 == n) {//경로 1-m1-n
		return d1[m1] + d2[m1];
	}
	if (d1[m1] >= INF || d2[m2] >= INF) {
		if (d1[m2] >= INF || d2[m1] >= INF) {//경로 X
			return -1;
		}
		return d1[m2] + d2[m1] + d3[m2];//1-m2-m1-n
	}
	if (d1[m2] >= INF || d2[m1] >= INF) {
		return d1[m1] + d2[m2] + d3[m2];
	}
	
	return d1[m1] + d2[m2] > d1[m2] + d2[m1] ? d1[m2] + d2[m1] + d3[m2] : d1[m1] + d2[m2] + d3[m2];
}

void dijkstra(int start,int**list,int*distance,int*visited) {
	int i, j, current;
	for (i = 1; i <= n; i++) {
		distance[i] = list[start][i];
	}
	visited[start] = 1;
	for (i = 1; i <= n - 2; i++) {
		current = getMinIndex(distance,visited);
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

int getMinIndex(int*distance,int*visited) {
	int min = -1, index = 0, i;
	for (i = 1; i <= n; i++) {
		if (min == -1 && visited[i] == 0) {
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


void init() {
	int i,j;
	scanf("%d %d", &n, &e);
	arr = (int**)malloc((n + 1) * sizeof(int*));
	for (i = 0; i <= n; i++) {
		arr[i] = (int*)malloc((n + 1)* sizeof(int));
		for (j = 0; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	for (i = 0; i < e; i++) {
		scanf("%d %d %d", &start, &end, &value);
		if (arr[start][end] > value) {
			arr[start][end] = value;
			arr[end][start] = value;
		}
	}
	scanf("%d %d", &m1, &m2);
	d1 = (int*)calloc(n + 1, sizeof(int));
	v1 = (int*)calloc(n + 1, sizeof(int));
	d2 = (int*)calloc(n + 1, sizeof(int));
	v2 = (int*)calloc(n + 1, sizeof(int));
	d3 = (int*)calloc(n + 1, sizeof(int));
	v3 = (int*)calloc(n + 1, sizeof(int));


}

void finish() {
	int i;
	for (i = 0; i <= n; i++) {
		free(arr[i]);
	}
	free(arr);
	free(d1);
	free(d2);
	free(d3);
	free(v1);
	free(v2);
	free(v3);
}