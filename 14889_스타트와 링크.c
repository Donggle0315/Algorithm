#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력 및 동적 할당
void finish();
//동적 해제
void backtracking(int, int);
//백트레킹을 사용하여 팀을 나눔
void findMinValue();
//팀 능력치를 조사하여 능력치 차이의 최소값을 찾음

int n;//선수 수
int** list;//선수 능력치
int* team;//팀 구성
int min = 1000000;//능력치 차이의 최소값

int main() {
	init();
	backtracking(0, 0);
	printf("%d", min);
	finish();

	return 0;
}

void backtracking(int start, int depth) {
	int i;
	if (depth == n / 2) {//팀이 다 채워졌을 떄
		findMinValue();//능력치 차이를 계산
		return;
	}
	for (i = start + 1; i <= n; i++) {//팀을 못고를 사람부터
		team[i] = 1;//i번쨰 사람이 1팀인 경우
		backtracking(i, depth + 1);//다음 사람을 고름
		team[i] = 0;//i번째 사람이 0팀인 경우
	}
}

void findMinValue() {
	int i, j, t1 = 0, t2 = 0, m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {//모든 선수에 대해
			if (i == j) {//같은 선수를 비교할 떄
				continue;
			}
			if (team[i] == 0 && team[j] == 0) {//둘다 0팀일 떄
				t1 += list[i][j];
			}
			else if (team[i] != 0 && team[j] != 0) {//둘다 1팀일 때
				t2 += list[i][j];
			}
		}
	}

	if (t1 > t2) {
		m = t1 - t2;
	}
	else {
		m = t2 - t1;
	}
	if (m < min) {//최소값이라면 
		min = m;//갱신
	}
}

void init() {
	int i, j;
	scanf("%d", &n);
	list = (int**)malloc((n + 1) * sizeof(int*));
	team = (int*)calloc(n + 1, sizeof(int));

	for (i = 1; i <= n; i++) {
		list[i] = (int*)malloc((n + 1) * sizeof(int));
		for (j = 1; j <= n; j++) {
			scanf("%d", &list[i][j]);
		}
	}
}

void finish() {
	int i;
	for (i = 1; i <= n; i++) {
		free(list[i]);
	}
	free(list);
	free(team);
}