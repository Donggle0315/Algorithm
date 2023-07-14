#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
long long findNumOfMakeBridge();

int n, m;
long long dp[30] = { 0 };

int main() {
	int i,tc;
	scanf("%d", &tc);

	for (i = 0; i < tc; i++) {
		init();
		printf("%lld\n", findNumOfMakeBridge());
	}

	return 0;
}

void init() {
	scanf("%d %d", &n, &m);
}


long long findNumOfMakeBridge() {
	int i,j;
	dp[1] = m;
	for (i = 2,j=m-1; i <= n; i++,j--) {
		dp[i] = dp[i - 1] * j / i;
	}
	return dp[n];
}