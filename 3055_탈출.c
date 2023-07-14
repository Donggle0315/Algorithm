#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
int bfs(int, int);
void addq(int, int, int);
void deleteq(int*, int*, int*);
int isEmpty();
void fillWater();

int r, c;
int** list;//0 ��ĭ 1 �� 2 �� 3 ��� 4 ����
int** visited;
int** water;
int waterCount;
int** queue;
int front;
int rear;
int starti;
int startj;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int main() {
	init();
	int re = bfs(starti, startj);
	if (re == -1) {
		printf("KAKTUS");
	}
	else {
		printf("%d", re);
	}
	finish();


	return 0;
}


void fillWater() {
	int k = waterCount;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) {
			int p = water[i][0] + dir[j][0];
			int q = water[i][1] + dir[j][1];

			if (p < 0 || p >= r || q < 0 || q >= c) {//������
				continue;
			}
			if (list[p][q] != 0) {//�ٸ��� �̹� �ִٸ�
				continue;
			}

			water[waterCount][0] = p;
			water[waterCount++][1] = q;
			list[p][q] = 2;

		}
	}
}

int bfs(int si,int sj) {
	int now_time = 1;
	visited[si][sj] = 1;
	addq(si, sj, 0);

	while (isEmpty() == 0) {
		int row, col,time;
		deleteq(&row, &col, &time);
		if (list[row][col] == 4) {//�����ߴ�
			return time;
		}
		if (list[row][col] == 2) {//�̹� ���� ���ִ�
			continue;
		}
		if (time != now_time) {//���� �ð��� �� ���Ұ� ������ ���� �۶߸�
			fillWater();
			now_time = time;
		}

		for (int i = 0; i < 4; i++) {//�� ���⿡ ����
			int p = row + dir[i][0];
			int q = col + dir[i][1];
			if (p < 0 || p >= r || q < 0 || q >= c) {//���� ��
				continue;
			}
			if (visited[p][q] == 1) {//�̹� �湮
				continue;
			}
			if (list[p][q] == 1 || list[p][q] == 2) {//���̰ų� ��
				continue;
			}

			visited[p][q] = 1;
			addq(p, q, time + 1);//�湮
		}
	}

	return -1;
}

void addq(int row, int col , int time) {
	queue[front][0] = row;
	queue[front][1] = col;
	queue[front++][2] = time;
}

void deleteq(int* row, int* col, int* time) {
	*row = queue[rear][0];
	*col = queue[rear][1];
	*time = queue[rear++][2];
}

int isEmpty() {
	if (front == rear) {
		return 1;
	}
	return 0;
}

void init() {
	scanf("%d %d", &r, &c);

	water = (int**)malloc(r * c * sizeof(int*));
	for (int i = 0; i < r * c; i++) {
		water[i] = (int*)malloc(2 * sizeof(int));
	}
	waterCount = 0;

	queue = (int**)malloc(r * c * sizeof(int*));
	for (int i = 0; i < r * c; i++) {
		queue[i] = (int*)malloc(3 * sizeof(int));
	}
	front = 0;
	rear = 0;

	list = (int**)malloc(r * sizeof(int*));
	visited = (int**)malloc(r * sizeof(int*));
	for (int i = 0; i < r; i++) {
		list[i] = (int*)malloc(c * sizeof(int));
		visited[i] = (int*)calloc(c, sizeof(int));
		char* str = (char*)malloc((c + 2) * sizeof(char));
		scanf("%s", str);
		for (int j = 0; j<c; j++) {
			if (str[j] == '.') {
				list[i][j] = 0;
			}
			else if (str[j] == 'X') {
				list[i][j] = 1;
			}
			else if (str[j] == '*') {
				list[i][j] = 2;
				water[waterCount][0] = i;
				water[waterCount++][1] = j;
			}
			else if (str[j] == 'S') {
				list[i][j] = 3;
				starti = i;
				startj = j;
			}
			else if(str[j]=='D'){
				list[i][j] = 4;
			}
		}
		free(str);
	}
}

void finish() {
	for (int i = 0; i < r * c; i++) {
		free(queue[i]);
		free(water[i]);
	}
	for (int i = 0; i < r; i++) {
		free(visited[i]);
		free(list[i]);
	}
	free(queue);
	free(water);
	free(list);
	free(visited);
}