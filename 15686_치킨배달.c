#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void init();
//입력 및 치킨집과 집의 좌표 저장
void backtracking(int, int);
//백트레킹을 이용하여 폐업할 가게를 선택하고 다 폐업시키면 거리 조사
void findMinDistance();
//모든 집의 거리의 합 중 최소를 조사
int nearStore(int);
//하나의 집에 대한 최소 거리 반환

int n, m;
int list[51][51];//지도
int store[14][2];//가게 좌표
int house[101][2];//집 좌표
int h = 0;//집의 개수
int s = 0;//가게 개수
int min = 0;//거리의 최솟값

int main() {
	init();
	backtracking(-1, 0);
	printf("%d", min);

	return 0;
}

void findMinDistance() {
	int sum = 0;
	int i;
	for (i = 0; i < h; i++) {//모든 집에 대해
		sum += nearStore(i);//최소 거리의 합
	}
	if (min == 0) {
		min = sum;
	}
	else if (sum < min) {//최소 거리의 합이 최소라면
		min = sum;
	}
}

int nearStore(int k) {
	int x, y;
	int i;
	int p =0;
	x = house[k][0];//집의 좌표
	y = house[k][1];
	for (i = 0; i < s; i++) {//모든 가게에 대해
		if (store[i][0] == -1) {//폐업한 가게라면
			continue;
		}
		if (p == 0) {//집에서 가게까지의 거리중 최소를 p에 저장
			p = abs(x - store[i][0]) + abs(y - store[i][1]);
		}
		else if(abs(x-store[i][0])+abs(y-store[i][1])<p){
			p = abs(x - store[i][0]) + abs(y - store[i][1]);
		}

	}
	return p;
}

void backtracking(int si, int depth) {
	int i,p,q;
	if (depth == s - m) {//남길만큼 남겼다면
		findMinDistance();//거리 조사
		return;
	}
	for (i = si + 1; i < s; i++) {//모든 가게에 대해
		p = store[i][0];
		q = store[i][1];
		store[i][0] = -1;//가게 폐업
		store[i][1] = -1;
		backtracking(i, depth + 1);//다음 가게 조사
		store[i][0] = p;//폐업한 가게 복구
		store[i][1] = q;
	}
}

void init() {
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &list[i][j]);
			if (list[i][j] == 2) {//치킨집 좌표 저장
				store[s][0] = i;
				store[s++][1] = j;
			}
			if (list[i][j] == 1) {//집 좌표 저장
				house[h][0] = i;
				house[h++][1] = j;
			}
		}
	}
}