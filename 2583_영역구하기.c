#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int row;
	int col;
	int** map;
	int** visited;
}graph;

void init();
//���� �Ҵ� �� �Է�
void deleteSquare();
//��ǥ�� �Է¹޾� �ش� ���� ����
int countArea();
//������ ������ ���̸� ����
int dfs(int, int);
//�� ������ dfs
void finish();
//���� �迭 ����
void sort(int, int);
//����


int* list;//������ ���̸� ����
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//������ ��Ÿ��
graph* gp;

int main() {
	int i,c;
	init();
	c = countArea();
	sort(0, c - 1);
	printf("%d\n", c);
	for (i = 0; i < c; i++) {
		printf("%d ", list[i]);
	}
	finish();
}

void init() {
	int i,k;
	gp = (graph*)malloc(sizeof(graph));
	scanf("%d %d %d", &gp->row, &gp->col, &k);
	gp->map = (int**)malloc(gp->row * sizeof(int*));
	gp->visited = (int**)malloc(gp->row * sizeof(int*));
	for (i = 0; i < gp->row; i++) {
		gp->map[i] = (int*)calloc(gp->col, sizeof(int));
		gp->visited[i] = (int*)calloc(gp->col, sizeof(int));
	}
	for (i = 0; i < k; i++) {//k���� ���Ͽ� ��ǥ�� �Է¹޾� �ش� ���� ����
		deleteSquare();

	}
	list = (int*)malloc(gp->row * gp->col * sizeof(int));
}

void deleteSquare() {
	int i, j;
	int x1, x2, y1, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	for (i = y1; i < y2; i++) {
		for (j = x1; j < x2; j++) {
			gp->map[i][j] = 1;//�Է¹��� ��ǥ�� ������ 1�� �ٲپ� ���������� �˷���
		}
	}
}

int countArea() {
	int count = 0;
	int i, j;
	for (i = 0; i < gp->row; i++) {
		for (j = 0; j < gp->col; j++) {
			if (gp->visited[i][j] == 0 && gp->map[i][j] == 0) {//������ �� �ְ�, �湮���� �ʾҴٸ�
				list[count++]=dfs(i, j);//dfs ��ȯ������ �ش� ������ ũ�Ⱑ ������, count�� ������ ������ ��Ÿ��
			}
		}
	}
	return count;//������ ���� ��ȯ
}

int dfs(int r, int c) {
	int i, p, q;
	int count = 0;//������ ����
	gp->visited[r][c] = 1;
	count++;//���� +1
	for (i = 0; i < 4; i++) {
		p = r + dir[i][0];
		q = c + dir[i][1];
		if (p < 0 || p >= gp->row) {//���� ��
			continue;
		}
		if (q < 0 || q >= gp->col) {//���� ��
			continue;
		}
		if (gp->visited[p][q] == 1) {//�̹� �湮�ߴٸ�
			continue;
		}
		if (gp->map[p][q] == 1) {//������ �� ���ٸ�
			continue;
		}
		count+=dfs(p, q);//������ ���̸� ��ȯ�޾� �߰�
	}
	return count;//������ ���� ��ȯ
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
	free(list);
}

void sort(int left, int right) {//������ �̿�
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2];
	int tmp;
	do {
		while (list[pl] < x) {
			pl++;
		}
		while (list[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			tmp = list[pl];
			list[pl] = list[pr];
			list[pr] = tmp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		sort(left, pr);
	}
	if (pl < right) {
		sort(pl, right);
	}
}