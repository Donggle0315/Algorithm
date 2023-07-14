#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int x;
	int next;
	int count;
	int isvisited;
}node;

typedef struct graph_pointer {
	int ladder;
	int snake;
	node* graph;
}graph_pointer;

void init();
void finish();
int findRoute();
void addq(int,int);
int deleteq();
int empty();


graph_pointer* gp;
int* queue;
int front;
int rear;

int main() {
	init();
	printf("%d", findRoute());
	finish();

	return 0;
}

void addq(int v,int c) {
	gp->graph[v].isvisited = 1;
	gp->graph[v].count = c;
	if (gp->graph[v].next != 0) {
		if (gp->graph[gp->graph[v].next].isvisited == 0) {
			addq(gp->graph[v].next, c);
		}
	}
	else {
		queue[front++] = v;
	}
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

int findRoute() {
	int i,v,p;
	for (i = 2; i <= 7; i++) {
		addq(i,1);
	}
	while (empty() == 0) {
		v = deleteq();
		if (v == 100) {
			return gp->graph[v].count;
		}
		for (i = 1; i < 7; i++) {
			p = i + v;
			if (p > 100) {
				continue;
			}
			if (gp->graph[p].isvisited == 1) {
				continue;
			}
			addq(p, gp->graph[v].count + 1);
		}
	}
	return -1;
}

void init() {
	int i,a,b;
	gp = (graph_pointer*)malloc(sizeof(graph_pointer));
	scanf("%d %d", &gp->ladder, &gp->snake);
	gp->graph = (node*)malloc(101 * sizeof(node));
	for (i = 1; i <= 100; i++) {
		gp->graph[i].x = i;
		gp->graph[i].count = 0;
		gp->graph[i].next = 0;
		gp->graph[i].isvisited = 0;
	}
	for (i = 0; i < gp->ladder; i++) {
		scanf("%d %d", &a, &b);
		gp->graph[a].next = b;
	}
	for (i = 0; i < gp->snake; i++) {
		scanf("%d %d", &a, &b);
		gp->graph[a].next = b;
	}
	queue = (int*)malloc(100 * sizeof(int));
	front = 0;
	rear = 0;
}

void finish() {
	free(gp->graph);
	free(gp);
	free(queue);
}