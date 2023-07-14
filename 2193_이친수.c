#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
long long findNumOfPinaryNumber();

int n;
long long dp[91][2] = { 0 };

int main() {
	init();
	printf("%lld", findNumOfPinaryNumber());

	return 0;
}

void init() {
	scanf("%d", &n);
}

long long findNumOfPinaryNumber() {
	int i;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	return dp[n][0] + dp[n][1];
}