#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
int countIncreaseNum();

int n;
int dp[10][1001] = { 0 };

int main() {

	init();
	printf("%d", countIncreaseNum());
	
	return 0;
}

void init() {
	scanf("%d", &n);
}

int countIncreaseNum() {
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0) {
				dp[i][j] = 1;
			}
			else if (j == 0) {
				dp[i][j] = i+1;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%10007;
			}
		}
	}
	return dp[9][n-1];
}