#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int row;
	int col;
}node;

typedef struct dir {
	int t;
	char d;
}dir;

void init();
void finish();
void addq(int, int);
void deleteq();
void playTheGame();
void makeMove();
int isMove();
void changeDirection();

int n, k, l;
int time;
int** list;
node* queue;
int front;
int rear;
dir* direction;
int dp;
int toward;//0:������ 1: �Ʒ� 2: ���� 3: ��
int to[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main() {
	init();
	playTheGame();
	finish();

	return 0;
}

void playTheGame() {
	while (1) {
		if (isMove() == 0) {
			printf("%d", time+1);
			break;
		}
		makeMove();
		time++;
		changeDirection();
	}
}


void makeMove() {
	int hp = queue[front - 1].row + to[toward][0];
	int hq = queue[front - 1].col + to[toward][1];
	if (list[hp][hq] != 1) {//����� ���ٸ�
		deleteq();//���� �ϳ� ����
	}
	addq(hp, hq);
}

int isMove() {
	//���� ������ 1, ������ 0 ��ȯ
	//�� �� ���� ��� : ������ �����ų�, ���뿡 ������,
	int hi = queue[front - 1].row;
	int hj = queue[front - 1].col;
	int hp = hi + to[toward][0];
	int hq = hj + to[toward][1];
	if (hp < 0 || hq < 0 || hp >= n || hq >= n) {//���� �ڴ� ���
		return 0;
	}
	if (list[hp][hq] == 2) {//������ ���뿡 �ڴ´�
		return 0;
	}
	
	return 1;
}

void changeDirection() {
	if (dp == l) {
		return;
	}
	if (time == direction[dp].t) {//���� ����
		if (direction[dp].d == 'D') {
			toward = (toward + 1) % 4;
		}
		else if (direction[dp].d == 'L') {
			if (toward == 0) {
				toward = 3;
			}
			else {
				toward--;
			}
		}
		dp++;
	}
}


void init() {
	scanf("%d", &n);
	scanf("%d", &k);
	list = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		list[i] = (int*)calloc(n, sizeof(int));
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		list[x - 1][y - 1] = 1;//�����ġ
	}
	scanf("%d", &l);
	direction = (dir*)malloc(l * sizeof(dir));
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		scanf("%d %c", &a, &b);
		direction[i].t = a;
		direction[i].d = b;
	}
	dp = 0;
	queue = (node*)malloc(10001 * sizeof(node));
	front = 0;
	rear = 0;
	addq(0, 0);
	toward = 0;
	time = 0;
}

void finish() {
	for (int i = 0; i < n; i++) {
		free(list[i]);
	}
	free(list);
	free(queue);
	free(direction);
}

void addq(int a, int b) {
	queue[front].row = a;
	queue[front++].col = b;
	list[a][b] = 2;
}

void deleteq() {
	list[queue[rear].row][queue[rear].col] = 0;
	rear++;
	
}
