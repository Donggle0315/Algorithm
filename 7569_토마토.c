#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int hei;//쌓아올려지는 상자
	int row;
	int col;
	int*** map;
	int*** visited;
}graph;

typedef struct node {
	int h;//z축
	int r;//y축
	int c;//x축
	int day;
}node;

void init();
//동적 배열 할당 및 입력
void finish();
//동적 해제
int isFinish();
//안익은 토마토가 있으면 -1반환,다 익었다면 다 익은 날짜 반환
int bfs();
//bfs실시하여 하루 단위로 토마토를 익게 함. 더 이상 익을 토마토가 없을때, 해당 날짜 반환
void addq(int,int, int, int);
//큐 add
void deleteq(node*);
//큐 delelte
int empty();
//비었으면 1, 아니면 0반환

graph* gp;
int dir[6][3] = { {0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0} };//상하동서남북 방향
node* queue;
int front;
int rear;


int main() {
	init();
	printf("%d", isFinish());;
	finish();

	return 0;
}

void init() {
	int i, j,k;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d %d", &gp->col, &gp->row,&gp->hei);
	queue = (node*)malloc(gp->row * gp->col * gp->hei*sizeof(node));
	front = 0;
	rear = 0;
	gp->map = (int***)malloc(gp->hei * sizeof(int**));
	gp->visited = (int***)malloc(gp->hei * sizeof(int**));
	for (i = 0; i < gp->hei; i++) {
		gp->map[i] = (int**)malloc(gp->row * sizeof(int*));
		gp->visited[i] = (int**)calloc(gp->row, sizeof(int*));
		for (j = 0; j < gp->row; j++) {
			gp->map[i][j] = (int*)malloc(gp->col * sizeof(int));
			gp->visited[i][j] = (int*)calloc(gp->col, sizeof(int));
			for (k = 0; k < gp->col; k++) {
				scanf("%d", &gp->map[i][j][k]);
				if (gp->map[i][j][k] == 1) {//토마토가 있다면 해당 위치 queue에 저장
					queue[front].h = i;
					queue[front].r = j;
					queue[front].c = k;
					queue[front++].day = 0;//초기 값이므로 0일
				}
			}
			
		}
	}
}

void finish() {
	int i,j;
	for (i = 0; i < gp->hei; i++) {
		for (j = 0; j < gp->row; j++) {
			free(gp->map[i][j]);
			free(gp->visited[i][j]);
		}
		free(gp->map[i]);
		free(gp->visited[i]);
	}
	free(gp->map);
	free(gp->visited);
	free(gp);
	free(queue);
}

int isFinish() {
	int i, j,k;
	int day = bfs();
	for (i = 0; i < gp->hei; i++) {
		for (j = 0; j < gp->row; j++) {
			for (k = 0; k < gp->col; k++) {
				if (gp->map[i][j][k] == 0) {//vfs를 했는데 안익은 토마토가 있다면
					return -1;
				}
			}
			
		}
	}
	return day;
}

int bfs() {
	int i,o, p, q;
	node* w = (node*)malloc(sizeof(node));
	for (i = 0; i < front; i++) {//이미 있는 토마토들에 대해
		gp->visited[queue[i].h][queue[i].r][queue[i].c] = 1;
	}
	while (empty() == 0) {
		deleteq(w);
		for (i = 0; i < 6; i++) {//상하동서남북 방향으로
			o = w->h + dir[i][0];
			p = w->r + dir[i][1];
			q = w->c + dir[i][2];
			if (o < 0 || o >= gp->hei) {//범위 밖
				continue;
			}
			if (p < 0 || p >= gp->row) {//범위 밖
				continue;
			}
			if (q < 0 || q >= gp->col) {//범위 밖
				continue;
			}
			if (gp->map[o][p][q] == -1 || gp->map[o][p][q] == 1) {//벽이거나 이미 토마토가 있다면
				continue;
			}
			if (gp->visited[o][p][q] == 1) {//이미 방문했다면
				continue;
			}
			gp->map[o][p][q] = 1;//익은 토마토로 변경
			gp->visited[o][p][q] = 1;//방문했고
			addq(o,p, q, w->day + 1);//하루 뒤 익은 토마토로 저장
		}
	}
	i = w->day;//마지막에 남은 토마토가 가장 마지막날 익은 토마토
	free(w);
	return i;//날짜 반환
}

void addq(int h,int r, int c, int day) {
	queue[front].h = h;
	queue[front].r = r;
	queue[front].c = c;
	queue[front++].day = day;
}

void deleteq(node* w) {
	w->h = queue[rear].h;
	w->r = queue[rear].r;
	w->c = queue[rear].c;
	w->day = queue[rear++].day;
}

int empty() {
	if (front == rear) {
		return 1;
	}
	return 0;
}
