#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int row;
	int col;
	int** map;
	int** visited;
}graph;

typedef struct node {
	int r;
	int c;
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
void addq(int, int, int);
//ť add
void deleteq(node*);
//ť delelte
int empty();
//������� 1, �ƴϸ� 0��ȯ

graph* gp;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿� ����
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
	int i, j;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d", &gp->col, &gp->row);
	queue = (node*)malloc(gp->row * gp->col * sizeof(node));
	front = 0;
	rear = 0;
	gp->map = (int**)malloc(gp->row * sizeof(int*));
	gp->visited = (int**)malloc(gp->row * sizeof(int*));
	for (i = 0; i < gp->row; i++) {
		gp->map[i] = (int*)malloc(gp->col * sizeof(int));
		gp->visited[i] = (int*)calloc(gp->col, sizeof(int));
		for (j = 0; j < gp->col; j++) {
			scanf("%d", &gp->map[i][j]);
			if (gp->map[i][j] == 1) {//�丶�䰡 �ִٸ� �ش� ��ġ queue�� ����
				queue[front].r = i;
				queue[front].c = j;
				queue[front++].day = 0;//�ʱ� ���̹Ƿ� 0��
			}
		}
	}
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

int isFinish() {
	int i, j;
	int day = bfs();
	for (i = 0; i < gp->row; i++) {
		for (j = 0; j < gp->col; j++) {
			if (gp->map[i][j] == 0) {//vfs�� �ߴµ� ������ �丶�䰡 �ִٸ�
				return -1;
			}
		}
	}
	return day;
}

int bfs() {
	int i, p, q;
	node* w=(node*)malloc(sizeof(node));
	for (i = 0; i < front; i++) {//�̹� �ִ� �丶��鿡 ����
		gp->visited[queue[i].r][queue[i].c] = 1;
	}
	while (empty() == 0) {
		deleteq(w);
		for (i = 0; i < 4; i++) {//�����¿� �������� 
			p = w->r + dir[i][0];
			q = w->c + dir[i][1];
			if (p < 0 || p >= gp->row) {//���� ��
				continue;
			}
			if (q < 0 || q >= gp->col) {//���� ��
				continue;
			}
			if (gp->map[p][q] == -1 || gp->map[p][q] == 1) {//���̰ų� �̹� �丶�䰡 �ִٸ�
				continue;
			}
			if (gp->visited[p][q] == 1) {//�̹� �湮�ߴٸ�
				continue;
			}
			gp->map[p][q] = 1;//���� �丶��� ����
			gp->visited[p][q] = 1;//�湮�߰�
			addq(p, q, w->day + 1);//�Ϸ� �� ���� �丶��� ����
		}
	}
	i = w->day;//�������� ���� �丶�䰡 ���� �������� ���� �丶��
	free(w);
	return i;//��¥ ��ȯ
}

void addq(int r, int c, int day) {
	queue[front].r = r;
	queue[front].c = c;
	queue[front++].day = day;
}

void deleteq(node* w) {
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
