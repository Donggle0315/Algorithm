#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
int findMaxDrinkDP();
int Max(int, int);
int num;
int input[10001];
int dp[10001];


int main() {
	init();
	printf("%d", findMaxDrinkDP());

	return 0;
}

void init() {
	int i;
	scanf("%d", &num);
	for (i = 1; i <= num; i++) {
		scanf("%d", &input[i]);
	}
}

int findMaxDrinkDP() {
	int i;
	dp[0] = 0;
	dp[1] = input[1];
	dp[2] = dp[1]+input[2];
	for (i = 3; i <= num; i++) {
		dp[i] = Max(dp[i - 2] + input[i],dp[i - 3] + input[i - 1] + input[i]);
		dp[i] = Max(dp[i - 1], dp[i]);
	}
	return dp[num];
}

int Max(int a, int b) {
	return a > b ? a : b;
}