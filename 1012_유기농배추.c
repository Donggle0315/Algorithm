#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct table {
	int row;//����
	int col;//����
	int** arr;//������ ��ġ ǥ�� 0: ���� 1: ����
	int** visited;//�湮 ���� ǥ��
	int k;//������ ����
	int count;//�������� ����
}table;

void init();
//�ʱ�ȭ �Լ�
void finish();
//���� ���� �Լ�
void dfs(int,int);
//dfs�� ���߰� �ִ� ���� �湮
int findMin();
//�ʿ��� ������ ���� ����

int testCase;
table* tp;
int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0}};//�����¿츦 ǥ��


int main() {
	int i;
	scanf("%d", &testCase);
	for (i = 0; i < testCase; i++) {
		init();
		printf("%d\n", findMin());
		finish();
	}

	return 0;
}

int findMin() {
	int i, j;
	for (i = 0; i < tp->row; i++) {
		for (j = 0; j < tp->col; j++) {
			if (tp->arr[i][j] == 0) {//���߰� ���ٸ�
				continue;
			}
			if (tp->visited[i][j] == 1) {//�̹� �湮 �ߴٸ�
				continue;
			}
			dfs(j,i);//���߰� �ִµ� �湮���� ���� ���� ���� dfs�ǽ��Ͽ� ����� �� ����
			(tp->count)++;//������ �Ѹ��� �߰�
		}
	}
	return tp->count;
}

void dfs(int x, int y) {
	int i,p,q;
	
	tp->visited[y][x] = 1;
	for (i = 0; i < 4; i++) {//�����¿쿡 ���ؼ� �� ���� �ִ��� ����
		p = dir[i][0];//y��ǥ
		q = dir[i][1];//x��ǥ
		if (y + p<0 || y + p>tp->row - 1) {//y��ǥ�� �迭 ��
			continue;
		}
		if (x + q<0 || x + q>tp->col - 1) {//x��ǥ�� �迭 ��
			continue;
		}
		if (tp->arr[y + p][x + q] == 0) {//���߰� ���� ���
			continue;
		}
		if (tp->visited[y + p][x + q] == 1) {//�̹� �湮�� ���
			continue;
		}
		dfs(x+q,y+p);
	}
}

void init() {
	int i, x,y;
	tp = (table*)malloc(sizeof(table));
	scanf("%d %d %d", &tp->col, &tp->row, &tp->k);
	tp->arr = (int**)malloc(tp->row* sizeof(int*));
	tp->visited = (int**)malloc(tp->row * sizeof(int*));
	for (i = 0; i < tp->row; i++) {
		tp->arr[i] = (int*)calloc(tp->col, sizeof(int));
		tp->visited[i] = (int*)calloc(tp->col, sizeof(int));
	}
	for (i = 0; i < tp->k; i++) {
		scanf(" %d %d", &x, &y);
		tp->arr[y][x] = 1;
	}
	tp->count = 0;
}

void finish() {
	int i;
	for (i = 0; i < tp->row; i++) {
		free(tp->arr[i]);
		free(tp->visited[i]);
	}
	free(tp->arr);
	free(tp->visited);
	free(tp);
}