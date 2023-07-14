#define _CRT_SECURE_NO_WARNINGS
#define DIV 1000000000

#include <stdio.h>
#include <stdlib.h>

long long countOfStairDP();

int num;
long long dp[100][10] = { 0 };

int main() {
	scanf("%d", &num);
	printf("%lld", countOfStairDP());


	return 0;
}

long long countOfStairDP() {
	int i,j;
	long long sum = 0;
	for (i = 1; i <= 9; i++) {
		dp[0][i] = 1;
	}
	for (i = 1; i < num; i++) {
		for (j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1]%DIV;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1]%DIV;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1]+dp[i-1][j+1])%DIV;
			}
		}
	}
	for (i = 0; i <= 9; i++) {
		sum += dp[num - 1][i];
	}
	return sum % DIV;
}