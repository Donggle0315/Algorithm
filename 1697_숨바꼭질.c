#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int* map;
	int* visited;
	int n;
	int k;
}graph;

void init();
void finish();
int bfs(int);
void addq(int);
int deleteq();
int empty();

graph* gp;
int* queue;
int front;
int rear;

int main() {
	init();
	printf("%d", bfs(gp->n));
	finish();

	return 0;
}

void init() {
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d", &gp->n, &gp->k);
	gp->map = (int*)calloc(100001, sizeof(int));
	gp->visited = (int*)calloc(100001, sizeof(int));
	queue = (int*)malloc(100001* sizeof(int));
	front = 0;
	rear = 0;
}

void finish() {
	free(gp->map);
	free(gp->visited);
	free(gp);
	free(queue);
}

int bfs(int v) {
	int second = 1;
	int last=v;
	int new_last=0;
	gp->visited[v] = 1;
	gp->map[v] = 0;
	addq(v);
	while (empty() == 0) {
		v = deleteq();
		if (v == gp->k) {
			return gp->map[gp->k];
		}
		if (v-1>=0&&gp->visited[v - 1] == 0) {
			addq(v - 1);
			gp->visited[v - 1] = 1;
			gp->map[v - 1] = second;
			new_last = v - 1;
		}
		if (v+1<=100000&&gp->visited[v + 1] == 0) {
			addq(v + 1);
			gp->visited[v + 1] = 1;
			gp->map[v + 1] = second;
			new_last = v + 1;
		}
		if (2*v<=100000&&gp->visited[v*2] == 0) {
			addq(v*2);
			gp->visited[v*2] = 1;
			gp->map[v *2 ] = second;
			new_last = v *2;
		}
		if (v == last) {
			last = new_last;
			second++;
		}
	}
	return -1;
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