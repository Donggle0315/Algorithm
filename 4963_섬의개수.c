#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
typedef struct island {
	int h;//����
	int w;//�ʺ�
	int** map;//����
	int** visited;//�湮 ���� 0 ���� 1 ����
	int count;//���� ����
}island;

int init();
//���� �迭 �Ҵ� �� �Է�
void finish();
//���� ����
void dfs(int, int);
//dfs�� ���� �ϳ��� ����� �� ã��
int findIsland();
//dfs�� ��� �߳Ŀ� ���� ���� ���� ��ȯ

island* ip;
int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };//8������ ��ǥ�� ǥ��

int main() {
	int re;
	while (1) {
		re = init();
		if (re == 1) {//0 0 �Է�
			free(ip);
			break;
		}
		printf("%d\n", findIsland());
		finish();
	}
}

int findIsland() {
	int i, j;
	for (i = 0; i < ip->h; i++) {
		for (j = 0; j < ip->w; j++) {
			if (ip->map[i][j] == 0) {//������ �ƴϸ�
				continue;
			}
			if (ip->visited[i][j] == 1) {//�̹� �湮 �ߴٸ�
				continue;
			}
			dfs(i, j);
			(ip->count)++;//���� ���� +1
		}
	}
	return ip->count;
}


void dfs(int y, int x) {
	int i, p, q;
	ip->visited[y][x] = 1;//�湮 üũ
	for (i = 0; i < 8; i++) {//8���� �������� ����
		p = dir[i][0];
		q = dir[i][1];
		if (y + p < 0 || y + p >= ip->h) {//y��ǥ�� ���� ������ ����
			continue;
		}
		if (x + q < 0 || x + q >= ip->w) {//x��ǥ�� ���� ������ ����
			continue;
		}
		if (ip->map[y + p][x + q] == 0) {//������ �ƴ϶��
			continue;
		}
		if (ip->visited[y + p][x + q] == 1) {//�̹� �湮 �ߴٸ�
			continue;
		}
		dfs(y + p, x + q);
	}
}

int init() {
	int i, j;
	ip = (island*)malloc(sizeof(island));
	scanf("%d %d", &ip->w, &ip->h);
	if (ip->w == 0 && ip->h == 0) {// 0 0 �ԷµǸ� ����
		return 1;
	}
	ip->map = (int**)malloc(ip->h * sizeof(int*));
	ip->visited = (int**)malloc(ip->h * sizeof(int*));
	for (i = 0; i < ip->h; i++) {
		ip->map[i] = (int*)malloc(ip->w * sizeof(int));
		ip->visited[i] = (int*)calloc(ip->w, sizeof(int));
		for (j = 0; j < ip->w; j++) {
			scanf("%d", &ip->map[i][j]);
		}
	}
	ip->count = 0;
	
	return 0;
}

void finish() {
	int i;
	for (i = 0; i < ip->h; i++) {
		free(ip->map[i]);
		free(ip->visited[i]);
	}
	free(ip->map);
	free(ip->visited);
	free(ip);
}