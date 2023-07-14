#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main() {
	int n,i;
	long long dp[91] = { 0 };
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 1;
	for (i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	printf("%lld", dp[n]);
	return 0;
}