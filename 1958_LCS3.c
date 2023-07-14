#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
//두 문자열 입력
int findLCSLen();
//최장공통부분수열을 찾아서 그 길이를 반환
int Max(int, int);
//큰 값을 반환


char str1[101];
char str2[101];
char str3[101];
int dp[101][101][101] = { 0 };

int main() {
	init();
	printf("%d\n", findLCSLen());
	return 0;
}

void init() {
	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);
}

int findLCSLen() {
	int i, j,k;
	for (i = 1; i <= strlen(str1); i++) {
		for (j = 1; j <= strlen(str2); j++) {
			for (k = 1; k <= strlen(str3); k++) {
				if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = Max(Max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
				}
			}
		}
	}
	return dp[strlen(str1)][strlen(str2)][strlen(str3)];
}



int Max(int a, int b) {
	return a > b ? a : b;
}