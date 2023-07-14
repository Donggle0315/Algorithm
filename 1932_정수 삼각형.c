#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력
int findMaxSumDP();
//DP로 각 칸마다 최대 누적값을 배열 dp에 저장한 뒤, 마지막줄에서 가장 큰 값을 반환
int Max(int, int);
//둘 중 더 큰 값 반환

int input[500][500];//입력 저장
int dp[500][500];//누적 값 저장
int n;

int main() {
	init();
	printf("%d", findMaxSumDP());

	return 0;
}

void init() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &input[i][j]);
		}
	}
}

int findMaxSumDP() {
	int i, j;
	int max;
	dp[0][0] = input[0][0];//초기값
	for (i = 1; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0) {//줄의 처음은 무조건 위에 있는 값을 더해주어야 하는 예외
				dp[i][j] = dp[i - 1][j] + input[i][j];
			}
			else {//왼쪽 위([i-1][j-1]과 오른쪽 위([i-1][j]) 중 큰 값과 현재의 값을 더하여 저장
				dp[i][j] = Max(dp[i - 1][j - 1], dp[i - 1][j]) + input[i][j];
			}
		}
	}
	max = dp[n - 1][0];
	for (i = 1; i < n; i++) {
		if (dp[n - 1][i] > max) {//마지막 줄에서 최대값을 max에 저장
			max = dp[n - 1][i];
		}
	}
	return max;
}


int Max(int a, int b) {
	return a > b ? a : b;
}