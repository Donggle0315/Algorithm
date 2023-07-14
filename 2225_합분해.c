#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력 및 초기값 설정
int countSum();
//경우의 수 반환

int n, k;
int dp[201][201] = { 0 };

int main() {
	init();
	printf("%d", countSum());


	return 0;
}

void init() {
	int i;
	scanf("%d %d", &n, &k);
	for (i = 0; i <=n; i++) {//i를 하나의 수만으로 만드는 경우는 무조건 1가지
		dp[0][i] = 1;
	}
	for (i = 0; i < k; i++) {//0을 i개의 수만으로 만드는 경우는 무조건 1가지
		dp[i][0] = 1;
	}
}

int countSum() {
	int i, j;
	for (i = 1; i < k; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000000;
			//i+1개의 수로 j를 만드는 경우의 수는 dp[i-1][j]를 만드는 경우의 수에 0을 더하는 경우 & dp[i][j-1]에 하나의 수를 바꾸어 j로 만드는 경우
		}
	}
	return dp[k-1][n];
}