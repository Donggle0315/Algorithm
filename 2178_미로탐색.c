#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int r;
	//y��ǥ
	int c;
	//x��ǥ
	int moveCount;
	//�������� �������� �̵��� Ƚ��
}node;

typedef struct graph {
	int row;
	int col;
	int** map;
	int** visited;
}graph;

void init();
//���� �迭 �Ҵ� �� �Է�
void finish();
//���� ����
int bfs(int, int);
//bfs�� Ȱ���Ͽ� �̷� Ž��, ������ �̵� Ƚ���� ��ȯ
void addq(int, int, int);
//ť�� add(y��ǥ, x��ǥ, �̵�Ƚ��)
void deleteq(node*);
//ť���� delete
int empty();
//ť�� ����ִ��� Ȯ��, ����ٸ� 1�� �ƴ϶�� 0�� ��ȯ

graph* gp;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿� ����
node queue[10000];//ť
node* w;
int front, rear;//ť���� ����ϴ� ����

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
		for (i = 0; i < 4; i++) {//4���⿡ ����
			p = w->r + dir[i][0];
			q = w->c + dir[i][1];
			if (p == gp->row - 1 && q == gp->col - 1) {//�������� �����ߴٸ�
				return w->moveCount + 1;//�̵�Ƚ�� ��ȯ
			}
			if (p < 0 || p >= gp->row) {//���� ��
				continue;
			}
			if (q < 0 || q >= gp->col) {//���� ��
				continue;
			}
			if (gp->map[p][q] == 0) {//���� ���
				continue;
			}
			if (gp->visited[p][q] == 1) {//�̹� �湮 �ߴٸ�
				continue;
			}
			addq(p, q, w->moveCount + 1);//���� ��θ� ť�� add
			gp->visited[p][q] = 1;//�湮�������� ǥ��
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

