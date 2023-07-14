#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int vertex;
	struct node* link;
}node;

typedef struct graph_pointer {
	int vn;
	node* graph;
	int* visited;
}graph_pointer;

typedef struct queue_pointer {
	int front;
	int rear;
	int* queue;
}queue_pointer;


void init();
void insertVertex(int, int);
void dfs(int);
void bfs(int);
void initqueue();
void addq(int);
int deleteq();
int empty();
void initVisited();

graph_pointer* gp;
queue_pointer* qp;
int start;


int main() {
	init();
	dfs(start);
	printf("\n");
	initVisited();
	bfs(start);
	return 0;
}


void dfs(int v) {
	node* w;
	gp->visited[v - 1] = 1;
	printf("%d ", v);
	for (w = &(gp->graph[v - 1]); w; w = w->link) {
		if (gp->visited[(w->vertex) - 1] == 0) {
			dfs(w->vertex);
		}
	}
}

void bfs(int v) {
	node* w;
	initqueue();
	printf("%d ", v);
	gp->visited[v - 1] = 1;
	addq(v);
	while (empty() == 1) {//큐에 원소가 있으면
		v = deleteq();
		for (w = &(gp->graph[v - 1]); w; w = w->link) {
			if (gp->visited[(w->vertex) - 1] == 0) {
				printf("%d ", w->vertex);
				addq(w->vertex);
				gp->visited[(w->vertex) - 1] = 1;
			}
		}
	}

}

void initqueue() {
	qp = (queue_pointer*)malloc(sizeof(queue_pointer));
	qp->front = 0;
	qp->rear = 0;
	qp->queue = (int*)malloc(2*gp->vn * sizeof(int));
}

void addq(int v) {
	qp->queue[(qp->front)++] = v;
}

int deleteq() {
	return qp->queue[(qp->rear)++];
}

int empty() {
	if (qp->rear == qp->front) {
		return 0;
	}
	return 1;
}

void initVisited() {
	int i;
	for (i = 0; i < gp->vn; i++) {
		gp->visited[i] = 0;
	}
}

void init() {
	int a,b,n, m,i;
	gp = (graph_pointer*)malloc(sizeof(graph_pointer));
	scanf("%d %d %d", &n, &m, &start);
	gp->vn = n;
	gp->graph = (node*)malloc(n * sizeof(node));
	gp->visited = (int*)malloc(n * sizeof(int));
	for (i = 0; i < gp->vn; i++) {
		gp->graph[i].vertex = i + 1;
		gp->graph[i].link = NULL;
		gp->visited[i] = 0;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		insertVertex(a, b);
	}
}

void insertVertex(int a, int b) {
	node* np;
	node* tmp = (node*)malloc(sizeof(node));
	tmp->vertex = b;
	tmp->link = NULL;
	np = gp->graph[a - 1].link;
	if (np == NULL) {
		gp->graph[a - 1].link = tmp;
	}
	else if (tmp->vertex < np->vertex) {
		tmp->link = np;
		gp->graph[a - 1].link = tmp;
	}
	else {
		while (np->link != NULL) {
			if (tmp->vertex < np->link->vertex) {
				break;
			}
			np = np->link;
		}
		if (np->link != NULL) {
			tmp->link = np->link;
		}
		np->link = tmp;
	}
	
	tmp = (node*)malloc(sizeof(node));
	tmp->vertex = a;
	tmp->link = NULL;
	np = gp->graph[b - 1].link;
	if (np == NULL) {
		gp->graph[b - 1].link = tmp;
	}
	else if (tmp->vertex < np->vertex) {
		tmp->link = np;
		gp->graph[b - 1].link = tmp;
	}
	else {
		while (np->link != NULL) {
			if (tmp->vertex < np->link->vertex) {
				break;
			}
			np = np->link;
		}
		if (np->link != NULL) {
			tmp->link = np->link;
		}
		np->link = tmp;
	}
} 
