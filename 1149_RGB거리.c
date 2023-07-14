#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력
int dp_house();
//dp를 이용하여 최소값을 찾음. 한줄에서 각 칸마다 최소가 되는 값을 dp에 저장하여, 마지막 줄에서 최소값 반환
int Min(int, int);
//더 작은 값 반환

int house[1000][3];//입력한 값 저장
int dp[1000][3];//현재까지의 최소 누적값 저장
int num;

int main() {
	init();
	dp_house();
	printf("%d", dp_house());

	return 0;
}

void init() {
	int i;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
	}
}

int dp_house() {
	int i;
	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];
	for (i = 1; i < num; i++) {
		//색이 겹치지 않으면서 더 작은 값과 현재의 값을 더하여 저장함
		dp[i][0] = Min(dp[i - 1][1], dp[i-1][2]) + house[i][0];
		dp[i][1] = Min(dp[i - 1][0], dp[i-1][2]) + house[i][1];
		dp[i][2] = Min(dp[i - 1][0], dp[i-1][1]) + house[i][2];
	}
	return Min(Min(dp[num - 1][0], dp[num - 1][1]), dp[num - 1][2]);//마지막 누적된 값 중 최소값을 반환
}

int Min(int a, int b) {
	return a < b ? a : b;
}
