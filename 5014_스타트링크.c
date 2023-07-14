#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
int bfs(int);
void addq(int, int);
int deleteq();
int isEmpty();

int* visited;
int* queue;
int front, rear;
int f,s,g,u,d;


int main() {
	init();
	int re = bfs(s);
	if (re == -1) {
		printf("use the stairs\n");
	}
	else {
		printf("%d", re);
	}
	finish();

	return 0;
}

void init() {
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	visited = (int*)calloc(f + 1, sizeof(int));
	queue = (int*)malloc((f+1)* sizeof(int));
	front = 0;
	rear = 0;
}

void finish() {
	free(visited);
	free(queue);
}

int bfs(int start) {
	addq(start, 1);

	while (isEmpty() == 0) {
		int w = deleteq();
		if (w == g) {
			return visited[w]-1;
		}
		int up = w + u;
		int down = w - d;
		if (up <= f&&visited[up]==0) {
			addq(up, visited[w] + 1);
		}
		if (down >= 1 && visited[down] == 0) {
			addq(down, visited[w] + 1);
		}
	}

	return -1;
}

void addq(int a, int time) {
	visited[a] = time;
	queue[front++] = a;
}

int deleteq() {
	return queue[rear++];
}

int isEmpty() {
	if (front == rear) {
		return 1;
	}
	return 0;
}