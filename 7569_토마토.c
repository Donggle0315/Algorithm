#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int hei;//�׾ƿ÷����� ����
	int row;
	int col;
	int*** map;
	int*** visited;
}graph;

typedef struct node {
	int h;//z��
	int r;//y��
	int c;//x��
	int day;
}node;

void init();
//���� �迭 �Ҵ� �� �Է�
void finish();
//���� ����
int isFinish();
//������ �丶�䰡 ������ -1��ȯ,�� �;��ٸ� �� ���� ��¥ ��ȯ
int bfs();
//bfs�ǽ��Ͽ� �Ϸ� ������ �丶�並 �Ͱ� ��. �� �̻� ���� �丶�䰡 ������, �ش� ��¥ ��ȯ
void addq(int,int, int, int);
//ť add
void deleteq(node*);
//ť delelte
int empty();
//������� 1, �ƴϸ� 0��ȯ

graph* gp;
int dir[6][3] = { {0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0} };//���ϵ������� ����
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
				if (gp->map[i][j][k] == 1) {//�丶�䰡 �ִٸ� �ش� ��ġ queue�� ����
					queue[front].h = i;
					queue[front].r = j;
					queue[front].c = k;
					queue[front++].day = 0;//�ʱ� ���̹Ƿ� 0��
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
				if (gp->map[i][j][k] == 0) {//vfs�� �ߴµ� ������ �丶�䰡 �ִٸ�
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
	for (i = 0; i < front; i++) {//�̹� �ִ� �丶��鿡 ����
		gp->visited[queue[i].h][queue[i].r][queue[i].c] = 1;
	}
	while (empty() == 0) {
		deleteq(w);
		for (i = 0; i < 6; i++) {//���ϵ������� ��������
			o = w->h + dir[i][0];
			p = w->r + dir[i][1];
			q = w->c + dir[i][2];
			if (o < 0 || o >= gp->hei) {//���� ��
				continue;
			}
			if (p < 0 || p >= gp->row) {//���� ��
				continue;
			}
			if (q < 0 || q >= gp->col) {//���� ��
				continue;
			}
			if (gp->map[o][p][q] == -1 || gp->map[o][p][q] == 1) {//���̰ų� �̹� �丶�䰡 �ִٸ�
				continue;
			}
			if (gp->visited[o][p][q] == 1) {//�̹� �湮�ߴٸ�
				continue;
			}
			gp->map[o][p][q] = 1;//���� �丶��� ����
			gp->visited[o][p][q] = 1;//�湮�߰�
			addq(o,p, q, w->day + 1);//�Ϸ� �� ���� �丶��� ����
		}
	}
	i = w->day;//�������� ���� �丶�䰡 ���� �������� ���� �丶��
	free(w);
	return i;//��¥ ��ȯ
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
