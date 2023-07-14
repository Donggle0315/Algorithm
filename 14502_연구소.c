#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int row;
	int col;
	int** map;//�Է¹��� ����
	int** copy;//������ ������ ������ ��, ���õ� �� 3���� �߰��� ����
	int** visited;//�湮 ����
}graph;

typedef struct node {
	int r;//��
	int c;//��
}node;

/*�ʱ� ���� �� ���� �Լ�*/
void init();
//���� �迭 �Ҵ� �� �Է�
void finish();
//���� ����

/*���������� ã�� �Լ�*/
int bfs(int,int);
//bfs�� ���� ���̷����� �۶߸�. ���̷����� ���� ������ ������ ��ȯ
int findSafeZone();
//�� ��(0)�� 3���� �����Ͽ� ����� ������ ���� ���� ��, �ش� ������ �������� ���̷����� �ִ� ���� ���� bfs�ǽ�. ���̷����� ���� ���� ���� ��쿡�� �������� ���� ��ȯ
void makeCopyMap();
//gp->copy�� gp->map�� ����
void deleteCopy();
//�����Ҵ�� gp->copy�� ���� �����ϰ�, ���� ������ ���� ������ �ʱ�ȭ


/*ť ���� �Լ�*/
void addq(int, int);
//ť add(��, ��)
void deleteq(node*);
//ť delete(node�� ���� ����)
int empty();
//ť�� ����ٸ� 1, �ƴϸ� 0 ��ȯ


graph* gp;
node queue[64];
front = 0;
rear = 0;

node* virus;//���̷����� ��ġ ���� ����
int vc;//���̷����� ����
node* blank;//����� ��ġ ���� ����
int bc;//����� ����
int wc;//���� ����
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//�����¿� ���� ����

int main() {
	init();
	printf("%d", findSafeZone());
	finish();

	return 0;
}


int findSafeZone() {
	int i, j, k,l;
	int count,min=64;
	for (i = 0; i < bc-2; i++) {
		for (j = i+1; j < bc-1; j++) {
			for (k = j + 1; k < bc; k++) {//bc(����� ����)�� 3���� ����
				makeCopyMap();//������ ������ gp->copy�� ����
				count = 0;//���̷����� ����
				gp->copy[blank[i].r][blank[i].c]=1;
				gp->copy[blank[j].r][blank[j].c] = 1;
				gp->copy[blank[k].r][blank[k].c] = 1;//gp->copy�� �� 3���� �����
				for (l = 0; l < vc; l++) {//���̷��� ������ŭ
					count+=bfs(virus[l].r,virus[l].c);//bfs�� ���̷����� �۶߸���, ���� ���̷��� ���� ����
				}
				if (count < min) {//���̷����� ���� ���� ��츦 min�� ����
					min = count;
				}
				deleteCopy();//���� Ž���� ���� �ʱ�ȭ
			}
		}
	}
	return (gp->row*gp->col-wc-3)-min;//��ü ������ ���� - ���� ���� - ���� ���� �� 3�� - �ּ����� ���̷��� ��
}

int bfs(int r,int c) {//bfs�� ���̷����� �۶߸�
	int i,p,q;
	int count = 0;//���̷����� ����
	node* w=(node*)malloc(sizeof(node));
	gp->visited[r][c] = 1;
	count++;
	addq(r, c);
	while (empty() == 0) {
		deleteq(w);
		for (i = 0; i < 4; i++) {//�����¿� ���⿡ ����
			p = w->r + dir[i][0];
			q = w->c + dir[i][1];
			if (p < 0 || p >= gp->row) {//���� ��
				continue;
			}
			if (q < 0 || q >= gp->col) {//���� ��
				continue;
			}
			if (gp->visited[p][q] == 1) {//�湮�ߴٸ�
				continue;
			}
			if (gp->copy[p][q] != 0) {//����� �ƴ϶��
				continue;
			}
			addq(p, q);
			count++;//���̷����� 1�� �þ
			gp->copy[p][q] = 2;//�ش� �� ���̷����� �ٲ�
			gp->visited[p][q] = 1;//�湮
		}
	}
	free(w);
	return count;//�� ���̷��� ���� ��ȯ
}

void makeCopyMap() {//���� ����
	int i, j;
	gp->copy = (int**)malloc(gp->row * sizeof(int*));
	for (i = 0; i < gp->row; i++) {
		gp->copy[i] = (int*)malloc(gp->col * sizeof(int));
		for (j = 0; j < gp->col; j++) {
			gp->copy[i][j] = gp->map[i][j];
			gp->visited[i][j] = 0;
		}
	}
}

void deleteCopy() {
	int i;
	for (i = 0; i < gp->row; i++) {
		free(gp->copy[i]);
	}
	free(gp->copy);
	front = 0;
	rear = 0;//ť �ʱ�ȭ
}

void addq(int r, int c) {
	queue[front].r = r;
	queue[front++].c = c;
}

void deleteq(node* w) {
	w->r = queue[rear].r;
	w->c = queue[rear++].c;
}

int empty() {
	if (rear == front) {
		return 1;
	}
	return 0;
}

void init() {
	int i, j;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d", &gp->row, &gp->col);

	virus = (node*)malloc(gp->row * gp->col * sizeof(node));
	vc = 0;
	blank = (node*)malloc(gp->row * gp->col * sizeof(node));
	bc = 0;

	gp->map = (int**)malloc(gp->row * sizeof(int*));
	gp->visited = (int**)malloc(gp->row * sizeof(int*));
	
	for (i = 0; i < gp->row; i++) {
		gp->map[i] = (int*)malloc(gp->col * sizeof(int));
		gp->visited[i] = (int*)calloc(gp->col, sizeof(int));
		for (j = 0; j < gp->col; j++) {
			scanf("%d", &gp->map[i][j]);
			if (gp->map[i][j] == 2) {//�ش� ĭ�� ���̷������
				virus[vc].r = i;
				virus[vc++].c = j;
			}
			else if (gp->map[i][j] == 0) {//�ش� ĭ�� ����̶��
				blank[bc].r = i;
				blank[bc++].c = j;
			}
			else {//�ش� ĭ�� ���̶��
				wc++;
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
	free(virus);
	free(blank);
}