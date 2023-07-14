#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
int CountTile(int);

int num;
int dp[1000001];


int main() {
	init();
	printf("%d", CountTile(num));


	return 0;
}

void init() {
	scanf("%d", &num);
	dp[1] = 1;
	dp[2] = 2;
}

int CountTile(int n) {
	int i;
	for (i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1])%15746;
	}
	return dp[n];
}