#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
int findMaxValue();

int n;
int card[1001];
int dp[1001] = { 0 };

int main() {

	init();
	printf("%d", findMaxValue());

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &card[i]);
	}
}

int findMaxValue() {
	int i,j;
	dp[0] = 0;
	for (i = 1; i <= n; i++) {
		for (j = i; j >= 0 / 2; j--) {
			if (dp[j] + card[i - j] > dp[i]) {
				dp[i] = dp[j] + card[i - j];
			}
		}
	}
	return dp[n];
}