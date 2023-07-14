#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct table {
	int row;//세로
	int col;//가로
	int** arr;//배추의 위치 표현 0: 없음 1: 있음
	int** visited;//방문 여부 표현
	int k;//배추의 개수
	int count;//지렁이의 개수
}table;

void init();
//초기화 함수
void finish();
//동적 해제 함수
void dfs(int,int);
//dfs로 배추가 있는 곳을 방문
int findMin();
//필요한 지렁이 수를 구함

int testCase;
table* tp;
int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0}};//상하좌우를 표현


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
			if (tp->arr[i][j] == 0) {//배추가 없다면
				continue;
			}
			if (tp->visited[i][j] == 1) {//이미 방문 했다면
				continue;
			}
			dfs(j,i);//배추가 있는데 방문하지 않은 곳에 대해 dfs실시하여 연결된 곳 조사
			(tp->count)++;//지렁이 한마리 추가
		}
	}
	return tp->count;
}

void dfs(int x, int y) {
	int i,p,q;
	
	tp->visited[y][x] = 1;
	for (i = 0; i < 4; i++) {//상하좌우에 대해서 갈 곳이 있는지 조사
		p = dir[i][0];//y좌표
		q = dir[i][1];//x좌표
		if (y + p<0 || y + p>tp->row - 1) {//y좌표가 배열 밖
			continue;
		}
		if (x + q<0 || x + q>tp->col - 1) {//x좌표가 배열 밖
			continue;
		}
		if (tp->arr[y + p][x + q] == 0) {//배추가 없을 경우
			continue;
		}
		if (tp->visited[y + p][x + q] == 1) {//이미 방문한 경우
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