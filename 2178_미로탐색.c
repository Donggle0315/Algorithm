#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int r;
	//y좌표
	int c;
	//x좌표
	int moveCount;
	//시작점을 기준으로 이동한 횟수
}node;

typedef struct graph {
	int row;
	int col;
	int** map;
	int** visited;
}graph;

void init();
//동적 배열 할당 및 입력
void finish();
//동적 해제
int bfs(int, int);
//bfs를 활용하여 미로 탐색, 도착시 이동 횟수를 반환
void addq(int, int, int);
//큐에 add(y좌표, x좌표, 이동횟수)
void deleteq(node*);
//큐에서 delete
int empty();
//큐가 비어있는지 확인, 비었다면 1을 아니라면 0을 반환

graph* gp;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상하좌우 방향
node queue[10000];//큐
node* w;
int front, rear;//큐에서 사용하는 변수

int main() {
	init();
	printf("%d", bfs(0, 0));
	finish();

	return 0;
}

void addq(int r, int c, int mc) {
	queue[front].r = r;
	queue[front].c = c;
	queue[front++].moveCount = mc;
}

void deleteq(node* n) {
	n->c = queue[rear].c;
	n->r = queue[rear].r;
	n->moveCount = queue[rear++].moveCount;
}

int empty() {
	if (rear == front) {
		return 1;
	}
	return 0;
}

int bfs(int r, int c) {
	int i, p, q;
	addq(r, c, 1);
	while (empty() == 0) {
		deleteq(w);
		for (i = 0; i < 4; i++) {//4방향에 대해
			p = w->r + dir[i][0];
			q = w->c + dir[i][1];
			if (p == gp->row - 1 && q == gp->col - 1) {//도착점에 도착했다면
				return w->moveCount + 1;//이동횟수 반환
			}
			if (p < 0 || p >= gp->row) {//범위 밖
				continue;
			}
			if (q < 0 || q >= gp->col) {//범위 밖
				continue;
			}
			if (gp->map[p][q] == 0) {//벽일 경우
				continue;
			}
			if (gp->visited[p][q] == 1) {//이미 방문 했다면
				continue;
			}
			addq(p, q, w->moveCount + 1);//다음 경로를 큐에 add
			gp->visited[p][q] = 1;//방문했음으로 표시
		}
	}
}


void init() {
	int i, j;
	char* str;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d", &gp->row, &gp->col);
	front = 0;
	rear = 0;
	str = (char*)malloc((gp->col + 1) * sizeof(char));
	gp->map = (int**)malloc(gp->row * sizeof(int*));
	gp->visited = (int**)malloc(gp->row * sizeof(int*));
	for (i = 0; i < gp->row; i++) {
		gp->map[i] = (int*)malloc(gp->col * sizeof(int));
		gp->visited[i] = (int*)calloc(gp->col, sizeof(int));
		scanf("%s", str);
		for (j = 0; j < gp->col; j++) {
			gp->map[i][j] = str[j] - '0';
		}
	}
	w = (node*)malloc(sizeof(node));
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
	free(w);
}

