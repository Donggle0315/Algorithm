#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int user;
	struct node* next;
}node;

typedef struct graph_pointer {
	int n;
	int m;
	node* graph;
	int* isVisited;
	int** KVN;
}graph_pointer;

void init();
int findKV();
void bfs(int);
void re_init();
void insertEdge(int, int);
void addq(int);
int deleteq();
int empty();
void finish();

graph_pointer* gp;
int* queue;
int front = 0;
int rear = 0;


int main() {
	init();

	
	printf("%d", findKV());
	finish();


	return 0;
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

int findKV() {
	int i,j;
	int idx;
	int min;
	int sum;
	for (i = 0; i < gp->n; i++) {
		bfs(i + 1);
		re_init();
	}
		
	idx = gp->n-1;
	min = 10000;
	for (i = gp->n-1; i>=0; i--) {
		sum = 0;
		for (j = 0; j < gp->n; j++) {
			sum += gp->KVN[i][j];
		}
		if (sum <= min) {
			min = sum;
			idx = i;
		}
	}
	return idx + 1;
}

void bfs(int v) {
	int origin = v;
	int last = v;
	int nlast;
	node* w;
	int kv = 1;
	gp->isVisited[v - 1] = 1;
	addq(v);
	while (empty() == 0) {
		v = deleteq();
		
		for (w = gp->graph[v - 1].next; w; w = w->next) {
			if (gp->isVisited[w->user - 1] == 0) {
				gp->KVN[origin-1][w->user - 1] = kv;
				addq(w->user);
				gp->isVisited[w->user - 1] = 1;
				nlast = w->user;
			}
		}
		if (v == last) {
			last = nlast;
			kv++;
		}
		
	}
}

void re_init() {
	int i;
	front = 0;
	rear = 0;
	for (i = 0; i < gp->n; i++) {
		gp->isVisited[i] = 0;
	}
}

void init() {
	int i,a,b;
	gp = (graph_pointer*)malloc(sizeof(graph_pointer));
	scanf("%d %d", &gp->n, &gp->m);
	gp->graph = (node*)malloc(gp->n * sizeof(node));
	gp->isVisited = (int*)calloc(gp->n, sizeof(int));
	gp->KVN = (int**)malloc(gp->n* sizeof(int*));
	for (i = 0; i < gp->n; i++) {
		gp->graph[i].user = i + 1;
		gp->graph[i].next = NULL;
		gp->KVN[i] = (int*)calloc(gp->n, sizeof(int));
	}
	for (i = 0; i < gp->m; i++) {
		scanf("%d %d", &a, &b);
		insertEdge(a, b);
	}
	queue = (int*)malloc(gp->n * sizeof(int));
}

void finish() {
	int i;
	for (i = 0; i < gp->n; i++) {
		free(gp->KVN[i]);
	}
	free(gp->graph);
	free(gp->isVisited);
	free(gp->KVN);
	free(gp);
	free(queue);
}

void insertEdge(int a, int b) {
	node* tmp;
	node* w = (node*)malloc(sizeof(node));
	w->user = b;
	w->next = NULL;
	tmp = &(gp->graph[a - 1]);
	if(tmp->next!=NULL) {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
	}
	tmp->next = w;

	w = (node*)malloc(sizeof(node));
	w->user = a;
	w->next = NULL;
	tmp = &(gp->graph[b - 1]);
	if (tmp->next != NULL) {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
	}
	tmp->next = w;
}