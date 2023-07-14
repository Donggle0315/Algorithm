#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int row;
	int col;
	char** map;
	int** visited;
}graph;

typedef struct node {
	int row;
	int col;
	int count;
}node;

void init();
//동적 배열 할당 및 입력
void finish();
//동적 해제
int bfs(int, int);
//해당 위치에서 bfs실시하고, 가장 먼 곳의 횟수 반환
int findMaxRoute();
//땅인곳에서 bfs를 실시하여 가장 먼 곳 중 최대의 수를 반환
void re_init();
//다음 케이스를 위한 큐 및 gp->visited 초기화
void addq(int, int, int);
//큐 add
void deleteq(node*);
//큐 delete
int empty();
//비었다면 1을 아니라면 0 반환

graph* gp;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//방향을 나타냄
int front;
int rear;
node* queue;


int main() {
	init();
	printf("%d", findMaxRoute());
	finish();

	return 0;
}

int findMaxRoute() {
	int max = 0,re;
	int i, j;
	for (i = 0; i < gp->row; i++) {
		for (j = 0; j < gp->col; j++) {
			if (gp->map[i][j] == 'L') {//육지라면
				re = bfs(i, j);//bfs를 실시하여 해당 좌표에서 가장 먼 육지 거리 반환
				if (re > max) {//가장 크다면
					max = re;
				}
				re_init();//다음 경우를 위한 초기화
			}
		}
	}
	return max;//최댓값 반환
}

void re_init() {
	int i, j;
	for (i = 0; i < gp->row; i++) {
		for (j = 0; j < gp->col; j++) {
			gp->visited[i][j] = 0;
		}
	}
	front = 0;
	rear = 0;
}

int bfs(int r, int c) {
	int i,p,q;
	node* w;
	w = (node*)malloc(sizeof(node));
	gp->visited[r][c] = 1;
	addq(r, c, 0);
	while (empty() == 0) {
		deleteq(w);
		for (i = 0; i < 4; i++) {//상하좌우에 대하여
			p = w->row + dir[i][0];
			q = w->col + dir[i][1];
			if (p < 0 || p >= gp->row) {//범위 밖
				continue;
			}
			if (q < 0 || q >= gp->col) {//범위 밖
				continue;
			}
			if (gp->map[p][q] == 'W') {//바다일 경우
				continue;
			}
			if (gp->visited[p][q] == 1) {//이미 방문 했다면
				continue;
			}
			addq(p, q, (w->count) + 1);//거리를 1 늘려서 add
			gp->visited[p][q]=1;
		}
	}
	i = w->count;//마지막에 남은 노드가 가장 긴 거리
	free(w);
	return i;
}

void addq(int r, int c, int k) {
	queue[front].row = r;
	queue[front].col = c;
	queue[front++].count = k;
}

void deleteq(node* w) {
	w->row = queue[rear].row;
	w->col = queue[rear].col;
	w->count = queue[rear++].count;
}

int empty() {
	if (front == rear) {
		return 1;
	}
	return 0;
}

void init() {
	int i,j;
	char* str;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d", &gp->row, &gp->col);
	str = (char*)malloc((gp->col + 1) * sizeof(char));
	gp->map = (char**)malloc(gp->row * sizeof(char*));
	gp->visited = (int**)malloc(gp->row * sizeof(int*));

	for (i = 0; i < gp->row; i++) {
		gp->map[i] = (char*)malloc(gp->col * sizeof(char));
		gp->visited[i] = (int*)calloc(gp->col, sizeof(int));
		scanf("%s", str);
		for (j = 0; j < gp->col; j++) {
			gp->map[i][j] = str[j];
		}
	}
	front = 0;
	rear = 0;
	queue = (node*)malloc(gp->row * gp->col * sizeof(node));
	free(str);
}

void finish() {
	int i;
	for (i = 0; i < gp->row; i++) {
		free(gp->map[i]);
		free(gp->visited[i]);
	}
	free(gp->map);
	free(gp->visited);
	free(gp);
	free(queue);
}