#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int recur_fibo(int);
int dynamic_fibo(int);

int num;
int* dp;
int re_count;
int dp_count;

int main() {
	scanf("%d", &num);
	dp = (int*)malloc((num + 1) * sizeof(int));
	re_count = 0;
	dp_count = 0;
	recur_fibo(num);
	dynamic_fibo(num);
	printf("%d %d", re_count, dp_count);
	free(dp);
	return 0;
}

int recur_fibo(int n) {
	if (n == 1 || n == 2) {
		re_count++;
		return 1;
	}
	return recur_fibo(n - 1) + recur_fibo(n - 2);
}

int dynamic_fibo(int n) {
	int i;
	dp[1] = 1;
	dp[2] = 1;
	for (i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp_count++;
	}
	return dp[n];
}
