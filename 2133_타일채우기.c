#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int dp[31] = { 0 };
	dp[0] = 1;
	int tmp = 0;
	for (int i = 2; i <= n; i += 2) {
		dp[i] = dp[i - 2] *3 + tmp*2;
		tmp += dp[i - 2];
	}

	printf("%d", dp[n]);


	return 0;
}