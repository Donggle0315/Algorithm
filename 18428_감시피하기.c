#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력 및 선생님 좌표 저장
void backtracking(int, int, int);
//백트레킹을 사용하여 벽을 세움. 3개의 벽을 세우면 선생님한테 걸리는지 조사
void print();
//결과를 YES||NO로 출력
int AvoidMonitor();
//감시당하는지 조사 감시당한다면 1을 아니라면 0을 반환
int teacherMonitor(int, int);
//선생님 한명의 감시를 조사. 감시하는 학생이 있다면 1을 아니라면 0을 반환

int n;
char list[10][10];//지도
int flag = 0;//감시여부. 감시하지 않는 경우가 있다면 1
int teacher[10][2];//선생님의 좌표
int nt = 0;//선생님수

int main() {
	init();
	backtracking(0, -1, 0);
	print();
	return 0;
}

void print() {
	if (flag == 1) {
		printf("YES");
	}
	else {
		printf("NO");
	}
}

int AvoidMonitor() {
	int i;
	for (i = 0; i < nt; i++) {//모든 선생님에 대해
		if (teacherMonitor(teacher[i][0], teacher[i][1]) == 1) {//감시하는 학생이 있다면
			return 1;
		}
	}//모든 선생님이 감시하는 학생이 없다면
	return 0;
}

int teacherMonitor(int si, int sj) {
	int i,ni,nj;
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상하좌우 방향에 대해
	for (i = 0; i < 4; i++) {
		ni = si;
		nj = sj;
		while (1) {
			ni += dir[i][0];
			nj += dir[i][1];
			if (ni<0 || ni>n - 1 || nj<0 || nj>n - 1 || list[ni][nj] == 'W') {//지도 끝까지가거나 벽에 막힌 경우
				break;
			}
			if (list[ni][nj] == 'S') {//학생을 감시한다면
				return 1;
			}
		}
	}//감시하는 학생이 없다면
	return 0;
}

void backtracking(int si,int sj,int depth) {
	int i, j;
	if (depth == 3) {//3개의 벽을 세웠다면
		if (AvoidMonitor() == 0) {//감시하는 학생이 없다면
			flag = 1;
		}
		return;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i < si) {//이전에 이미 조사
				continue;
			}
			if (i == si && j <= sj) {//이전에 이미 조사
				continue;
			}
			if (list[i][j] == 'X') {//벽을 세울 수 있는 공간이라면
				list[i][j] = 'W';//벽을 세우고
				backtracking(i, j, depth + 1);//다음 경우 조사
				list[i][j] = 'X';//벽을 다시 없앰
			}
		}
	}
}


void init() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf(" %c", &list[i][j]);
			if (list[i][j] == 'T') {//선생님의 좌표 저장
				teacher[nt][0] = i;
				teacher[nt++][1] = j;
			}
		}
	}
}
