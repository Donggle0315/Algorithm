#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
//입력
void backtracking(int, int, int);
//백트레킹을 사용하여 말이 움직일 수 있는 방향으로 이동하고 최대 거리 초기화

char list[21][21];//보드판에 알파벳 저장
int r, c;//세로 r 가로 c
int max = 0;//최대 이동 거리
int isvisited[26] = { 0 };//해당 알파벳 방문 여부


int main() {
	init();
	isvisited[list[0][0] - 'A'] = 1;//처음 시작하는 부분을 방문한 것으로 표기
	backtracking(0, 0, 1);
	printf("%d", max);

	return 0;
}

void backtracking(int si, int sj, int depth) {
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상하좌우 방향
	int i,p,q;
	
	if (depth > max) {//해당 이동거리가 최대일 때
		max = depth;
	}

	for (i = 0; i < 4; i++) {//상하좌우에 대해
		p = si + dir[i][0];
		q = sj + dir[i][1];
		if (p >= r || p < 0) {//범위 밖
			continue;
		}
		if (q >= c || q < 0) {//범위 밖
			continue;
		}
		if (isvisited[list[p][q]-'A'] == 1) {//이미 방문한 알파벳이라면
			continue;
		}
		isvisited[list[p][q]-'A'] = 1;//해당 알파벳을 방문
		backtracking(p, q, depth + 1);//다음 깊이로 탐색
		isvisited[list[p][q]-'A'] = 0;//알파벳 방문 취소
	}	
	
}

void init() {
	int i, j;
	char str[21];
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++) {
		scanf("%s", str);
		for (j = 0; j < c; j++) {
			list[i][j] = str[j];
		}
	}

}