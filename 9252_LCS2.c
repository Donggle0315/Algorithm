#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
//두 문자열 입력
int findLCSLen();
//최장공통부분수열을 찾아서 그 길이를 반환
void printLCSString();
//최장공통부분수열을 찾아서 그 문자열을 출력
int Max(int, int);
//큰 값을 반환


char str1[1001];
char str2[1001];
int dp[1001][1001] = { 0 };
char result[1001];

int main() {
	init();
	printf("%d\n", findLCSLen());
	printLCSString();

	return 0;
}

void init() {
	scanf("%s", str1);
	scanf("%s", str2);

}

int findLCSLen() {
	int i, j;
	for (i = 1; i <= strlen(str1); i++) {
		for (j = 1; j <= strlen(str2); j++) {
			if (str1[i - 1] == str2[j - 1]) {//두 문자가 같다면
				dp[i][j] = dp[i - 1][j - 1] + 1;//이전 dp에 1을 더해줌
			}
			else {//다르다면
				dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);//이전 dp중 큰 값을 저장
			}			
		}
	}
	return dp[strlen(str1)][strlen(str2)];
}

void printLCSString() {
	int i = strlen(str1);
	int j = strlen(str2);
	int len = 0;
	while (1) {
		if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else {
			result[len++] = str1[i-1];
			i--;
			j--;
		}
		if (i == 0 || j == 0) {
			break;
		}
	}
	for (i = len - 1; i >= 0; i--) {
		printf("%c", result[i]);
	}
	
}


int Max(int a, int b) {
	return a > b ? a : b;
}