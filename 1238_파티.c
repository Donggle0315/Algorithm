#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999;


#include <stdio.h>
#include <stdlib.h>

void init();
//입력 및 동적 배열 할당
void finish();
//동적 해제
void dijkstra(int, int*, int**, int*);
//다익스트라 알고리즘을 이용해 시작점부터의 최소 거리를 d에 저장
int getMinIndex(int*,int*);
//다익스트라 알고리즘 내에서 사용되는 함수
int findLongestTime();
//저장된 거리 배열 합의 최대를 반환

int n, m, x;
int** l;
int** rl;
int* d;
int* rd;
int* v;
int* rv;

int main() {
	init();
	dijkstra(x,d,l,v);//distance에 파티장->집까지의 최소거리 저장
	dijkstra(x,rd,rl,rv);//reversedistance에 집->파티장 최소거리 저장
	printf("%d", findLongestTime());
	finish();

	return 0;
}

int findLongestTime() {
	int max = 0;
	int i;
	for (i = 1; i <= n; i++) {
		if (i == x) {
			continue;
		}
		if (d[i] + rd[i] > max) {
			max = d[i] +rd[i];
		}
	}
	return max;
}


void init() {
	int i, j;
	int s, e, value;
	scanf("%d %d %d", &n, &m, &x);
	l = (int**)malloc((n + 1) * sizeof(int*));
	rl = (int**)malloc((n + 1) * sizeof(int*));

	d = (int*)calloc((n + 1), sizeof(int));
	v = (int*)calloc((n + 1), sizeof(int));
	rd = (int*)calloc((n + 1), sizeof(int));
	rv = (int*)calloc((n + 1), sizeof(int));

	for (i = 0; i <= n; i++) {
		l[i] = (int*)malloc((n + 1) * sizeof(int));//집->파티장까지의 경로
		rl[i] = (int*)malloc((n + 1) * sizeof(int));//파티장->집까지의 경로
		for (j = 0; j <= n; j++) {
			l[i][j] = INF;
			rl[i][j] = INF;
		}
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &e, &value);
		if (value < l[s][e]) {
			l[s][e] = value;
		}
		if (value < rl[e][s]) {
			rl[e][s] = value;
		}
	}
}

void finish() {
	int i;
	for (i = 0; i <= n; i++) {
		free(l[i]);
		free(rl[i]);
	}
	free(l);
	free(rl);
	free(v);
	free(d);
	free(rv);
	free(rd);
}

void dijkstra(int start,int* distance,int** list,int* visited) {
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

int getMinIndex(int* distance,int* visited) {
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