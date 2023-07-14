#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	char cmd;
	struct node* parent;
}node;

void init();
void finish();
void bfs(int);
void addq(int);
int deleteq();
int empty();
void printResult();
void re_init();

int data;
int goal;
int n;
node* list;
int* queue;
char* re;
int rc;
int front;
int rear;

int main() {
	int i;
	scanf("%d", &n);
	init();

	for (i = 0; i < n; i++) {
		re_init();
		bfs(data);
		printResult();
	}
	//finish();

	return 0;
}


void init() {
	int i;
	queue = (int*)malloc(10000 * sizeof(int));
	list = (node*)malloc(10000 * sizeof(node));
	for (i = 0; i < 10000; i++) {
		list[i].data = i;
		list[i].cmd = 'N';
		list[i].parent = NULL;
	}
	front = 0;
	rear = 0;
	re = (char*)malloc(5000 * sizeof(char));
	rc = 0;
}

void re_init() {
	int i;
	front = 0;
	rear = 0;
	rc = 0;
	for (i = 0; i < 10000; i++) {
		list[i].cmd = 'N';
		list[i].parent = NULL;
	}
	scanf("%d %d", &data,&goal);
}

void finish() {
	free(queue);
	free(list);
	free(re);
}

void printResult() {
	int i;
	node* w = &list[goal];
	while (w->parent != NULL) {
		re[rc++] = w->cmd;
		w = w->parent;
	}
	for (i = rc-1; i >= 0; i--) {
		printf("%c", re[i]);
	}
	printf("\n");
}

void bfs(int v) {
	int tmp,k;
	addq(v);
	list[v].cmd = 'F';
	while (empty() == 0) {
		v = deleteq();

		if (v == goal) {
			return;
			break;
		}
		tmp = (v * 2) % 10000;
		if (list[tmp].cmd=='N') {
			addq(tmp);
			list[tmp].cmd = 'D';
			list[tmp].parent = &list[v];
		}
		
		if (v == 0) {
			tmp = 9999;
		}
		else {
			tmp = v - 1;
		}
		if (list[tmp].cmd == 'N') {
			addq(tmp);
			list[tmp].cmd = 'S';
			list[tmp].parent = &list[v];
		}

		k = v / 1000;
		tmp = (v % 1000) * 10 + k;
		if (list[tmp].cmd=='N') {
			addq(tmp);
			list[tmp].cmd = 'L';
			list[tmp].parent = &list[v];
		}

		k = v % 10;
		tmp = (v / 10) + k * 1000;
		if (list[tmp].cmd == 'N') {
			addq(tmp);
			list[tmp].cmd = 'R';
			list[tmp].parent = &list[v];
		}

	}
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