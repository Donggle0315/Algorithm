#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력 및 동적 할당
void finish();
//동적 해제
void backtracking(int);
//백트레킹으로 퀸을 배치하고 모든 퀸이 배치 된다면 count++
int isAttack(int,int);
//퀸이 공격할 수 없는 위치에서는 1, 하면 0 반환

int n;//퀸의 개수
int* board;//퀸을 놓을 좌표를 저장
int count;//가능한 경우의 수

int main() {
	init();
	backtracking(0);
	printf("%d", count);
	finish();

	return 0;
}



void backtracking(int depth) {//depth는 놓인 퀸의 개수-1이자 퀸이 놓일 행의 좌표
	int j;
	if (depth == n) {//다 놓였다면
		count++;
		return;
	}
	
	for (j = 0; j < n; j++) {//j열에 대하여
		if (isAttack(depth,j)==1) {//놓을 수 있다면
			board[depth] = j;//퀸을 놓고
			backtracking(depth + 1);//다음 퀸 조사
			board[depth] = -1;//퀸 제거
		}
	}
			
}

int isAttack(int a,int b) {
	int i;
	for (i = 0; i < a; i++) {//이전 행에 대하여
		if (board[i] == b) {//같은 열에 위치
			return 0;
		}
		if (i + board[i] == a + b) {//같은 우상향 대각선에 위치
			return 0;
		}
		if (i - board[i] == a-b) {//같은 우하향 대각선에 위치
			return 0;
		}
	}//공격하지 않는 경우
	return 1;
}

void init() {
	int i;
	scanf("%d", &n);
	board = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++) {
		board[i] = -1;
	}
	count = 0;
}

void finish() {
	free(board);
}