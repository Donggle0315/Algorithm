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
//���� �迭 �Ҵ� �� �Է�
void finish();
//���� ����
int bfs(int, int);
//�ش� ��ġ���� bfs�ǽ��ϰ�, ���� �� ���� Ƚ�� ��ȯ
int findMaxRoute();
//���ΰ����� bfs�� �ǽ��Ͽ� ���� �� �� �� �ִ��� ���� ��ȯ
void re_init();
//���� ���̽��� ���� ť �� gp->visited �ʱ�ȭ
void addq(int, int, int);
//ť add
void deleteq(node*);
//ť delete
int empty();
//����ٸ� 1�� �ƴ϶�� 0 ��ȯ

graph* gp;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//������ ��Ÿ��
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
			if (gp->map[i][j] == 'L') {//�������
				re = bfs(i, j);//bfs�� �ǽ��Ͽ� �ش� ��ǥ���� ���� �� ���� �Ÿ� ��ȯ
				if (re > max) {//���� ũ�ٸ�
					max = re;
				}
				re_init();//���� ��츦 ���� �ʱ�ȭ
			}
		}
	}
	return max;//�ִ� ��ȯ
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
		for (i = 0; i < 4; i++) {//�����¿쿡 ���Ͽ�
			p = w->row + dir[i][0];
			q = w->col + dir[i][1];
			if (p < 0 || p >= gp->row) {//���� ��
				continue;
			}
			if (q < 0 || q >= gp->col) {//���� ��
				continue;
			}
			if (gp->map[p][q] == 'W') {//�ٴ��� ���
				continue;
			}
			if (gp->visited[p][q] == 1) {//�̹� �湮 �ߴٸ�
				continue;
			}
			addq(p, q, (w->count) + 1);//�Ÿ��� 1 �÷��� add
			gp->visited[p][q]=1;
		}
	}
	i = w->count;//�������� ���� ��尡 ���� �� �Ÿ�
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