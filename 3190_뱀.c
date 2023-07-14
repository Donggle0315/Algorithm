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
int toward;//0:오른쪽 1: 아래 2: 왼쪽 3: 위
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
	if (list[hp][hq] != 1) {//사과가 없다면
		deleteq();//꼬리 하나 줄임
	}
	addq(hp, hq);
}

int isMove() {
	//갈수 있으면 1, 없으면 0 반환
	//갈 수 없는 경우 : 벽으로 막히거나, 몸통에 박을떄,
	int hi = queue[front - 1].row;
	int hj = queue[front - 1].col;
	int hp = hi + to[toward][0];
	int hq = hj + to[toward][1];
	if (hp < 0 || hq < 0 || hp >= n || hq >= n) {//벽에 박는 경우
		return 0;
	}
	if (list[hp][hq] == 2) {//지렁이 몸통에 박는다
		return 0;
	}
	
	return 1;
}

void changeDirection() {
	if (dp == l) {
		return;
	}
	if (time == direction[dp].t) {//방향 변경
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
		list[x - 1][y - 1] = 1;//사과위치
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
