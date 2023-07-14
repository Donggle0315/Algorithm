#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct picture {
	int n;//����,����
	char** pic;//�� ���� ����
	int** visited;//�湮 ����
	int count;//���� ����
}picture;

void init();
//���� �迭 �Ҵ� �� �Է�
void finish();
//���� ����
void normaldfs(int,int,char);
//�������� �� �������� dfs
int dfscount(int);
//dfs�� �� ����� ���� ���� ��ȯ 0�̸� ����, 1�̸� ���ϻ��� ���� ���
void abnormaldfs(int,int,char);
//���ϻ������� �� �������� dfs
void initVisited();
//gp->visited �迭 �ʱ�ȭ

picture* gp;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿� ����

int main() {
	init();
	printf("%d ", dfscount(0));
	initVisited();
	printf("%d", dfscount(1));
	finish();

	return 0;
}

void initVisited() {
	int i, j;
	for (i = 0; i < gp->n; i++) {
		for (j = 0; j < gp->n; j++) {
			gp->visited[i][j] = 0;
		}
	}
}

int dfscount(int k) {
	int count = 0;
	int i,j;
	if (k == 0) {//������
		for (i = 0; i < gp->n; i++) {
			for (j = 0; j < gp->n; j++) {
				if (gp->visited[i][j] == 0) {//�湮���� �ʾҴٸ�
					normaldfs(j, i, gp->pic[i][j]);//dfs�ǽ�
					count++;//���� +1
				}
			}
		}
	}
	else {//���ϻ�����
		for (i = 0; i < gp->n; i++) {
			for (j = 0; j < gp->n; j++) {
				if (gp->visited[i][j] == 0) {//�湮���� �ʾҴٸ�
					abnormaldfs(j, i, gp->pic[i][j]);//dfs�ǽ�
					count++;//���� +1
				}
			}
		}
	}
	
	return count;
}

void normaldfs(int x, int y,char c) {
	int i, p, q;
	gp->visited[y][x] = 1;
	for (i = 0; i < 4; i++) {//�����¿쿡 ����
		p = dir[i][0];
		q = dir[i][1];
		if (y + p < 0 || y + p >= gp->n) {//������
			continue;
		}
		if (x+ q < 0 || x + q >= gp->n) {//���� ��
			continue;
		}
		if (gp->pic[y + p][x + q] != c) {//������ �ٸ� ���
			continue;
		}
		if (gp->visited[y + p][x + q] == 1) {//�̹� �湮�� ���
			continue;
		}
		normaldfs(x + q, y + p, c);
	}
}

void abnormaldfs(int x, int y, char c) {
	int i, p, q;
	gp->visited[y][x] = 1;
	for (i = 0; i < 4; i++) {//�����¿쿡 ����
		p = dir[i][0];
		q = dir[i][1];
		if (y + p < 0 || y + p >= gp->n) {//���� ��
			continue;
		}
		if (x + q < 0 || x + q >= gp->n) {//���� ��
			continue;
		}
		if (gp->visited[y + p][x + q] == 1) {//�̹� �湮�� ���
			continue;
		}
		if (c == 'R' || c == 'G') {//R�̳� G�� ���̴� ���
			if (gp->pic[y + p][x + q] == 'B') {//B�� ���
				continue;
			}
		}
		else if (c == 'B') {//B�� ���̴� ���
			if (gp->pic[y+p][x+q] == 'R' || gp->pic[y+p][x+q] == 'G') {//R�̳� G�� ���
				continue;
			}
		}
		abnormaldfs(x + q, y + p, c);
	}
}

void init() {
	int i,j;
	char* str;
	gp = (picture*)malloc(sizeof(picture));
	scanf("%d", &gp->n);
	gp->pic = (char**)malloc(gp->n * sizeof(char*));
	gp->visited = (int**)malloc(gp->n * sizeof(int*));
	str = (char*)malloc(((gp->n) + 1) * sizeof(char));
	for (i = 0; i < gp->n; i++) {
		gp->pic[i] = (char*)malloc((gp->n + 1) * sizeof(char));
		gp->visited[i] = (int*)calloc(gp->n , sizeof(int));
		scanf("%s", str);
		for (j = 0; j < gp->n; j++) {
			gp->pic[i][j] = str[j];
		}
	}
	gp->count = 0;
	free(str);
}

void finish() {
	int i;
	for (i = 0; i < gp->n; i++) {
		free(gp->pic[i]);
		free(gp->visited[i]);
	}
	free(gp->pic);
	free(gp->visited);
	free(gp);
}