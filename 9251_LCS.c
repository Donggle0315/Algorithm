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


char str1[1001];
char str2[1001];
int dp[1001][1001] = { 0 };


int main() {
	init();
	printf("%d", findLCSLen());


	return 0;
}

void init() {
	scanf("%s", str1);
	scanf("%s", str2);
	
}

int findLCSLen() {
	int i, j,max=0;
	for (i = 1; i <= strlen(str1); i++) {
		for (j = 1; j <= strlen(str2); j++) {
			if (str1[i-1] == str2[j-1]) {//두 문자가 같다면
				dp[i][j] = dp[i - 1][j - 1] + 1;//이전 dp에 1을 더해줌
			}
			else {//다르다면
				dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);//이전 dp중 큰 값을 저장
			}
			if (dp[i][j] > max) {//최댓값 찾기
				max = dp[i][j];
			}
		}
	}
	return max;
}

int Max(int a, int b) {
	return a > b ? a : b;
}