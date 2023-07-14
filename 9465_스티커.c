#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
int findMaxScore();
int Max(int, int);

int n;
int sticker[2][100001] = { 0 };
int dp[2][100001] = { 0 };



int main() {
	int tc, i;
	scanf("%d", &tc);
	for (i = 0; i < tc; i++) {
		init();
		printf("%d\n", findMaxScore());
	}


	return 0;
}

void init() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < 2; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &sticker[i][j]);
		}
	}
}

int findMaxScore() {
	int i,max;
	int j;
	
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[0][1] = sticker[0][1];
	dp[1][1] = sticker[1][1];
	max = Max(dp[0][1], dp[1][1]);
	for (i = 2; i <= n; i++) {
		dp[0][i] = sticker[0][i] + Max(Max(dp[0][i-2], dp[1][i-2]), dp[1][i-1]);
		if (dp[0][i] > max) {
			max = dp[0][i];
		}
		dp[1][i] = sticker[1][i] + Max(Max(dp[0][i-2], dp[1][i-2]), dp[0][i-1]);
		if (dp[1][i] > max) {
			max = dp[1][i];
		}
	}

	return max;
}

int Max(int a, int b) {
	return a > b ? a : b;
}