#define _CRT_SECURE_NO_WARNINGS
#define DIV 1000000007;

#include <stdio.h>
#include <stdlib.h>

void init();
void findRoute();


int n, m;
int list[1000][1000];
int dp[2][1000];

int main() {
	init();
	findRoute();

	return 0;
}

void findRoute() {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (list[0][i] == 1) {
			dp[0][i] = 1;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (list[i][j] == 0) {
				continue;
			}
			if (j - 1 >= 0) {
				dp[1][j] += dp[0][j - 1];
				dp[1][j] %= DIV;
			}
			if (j + 1 < m) {
				dp[1][j] += dp[0][j + 1];
				dp[1][j] %= DIV;
			}
			dp[1][j] += dp[0][j];
			dp[1][j] %= DIV;
		}
		for (int j = 0; j < m; j++) {
			dp[0][j] = dp[1][j];
			dp[1][j] = 0;
		}
		
	}

	for (int i = 0; i < m; i++) {
		sum += dp[0][i];
		sum %= DIV;
	}

	printf("%d", sum);
}

void init() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &list[i][j]);
		}
	}
	
}
