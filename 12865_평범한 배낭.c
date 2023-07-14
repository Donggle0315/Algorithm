#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력
int findMaxValueOfBackpack();
//최대 가치를 반환
int Max(int, int);
//큰 값 반환

int n, k;
int weight[100];//짐들의 무게 저장
int value[100];//짐들의 가치 저장
int dp[101][100001] = {0};

 
int main() {
	init();
	printf("%d", findMaxValueOfBackpack());

	return 0;
}

void init() {
	int i;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}
	
}

int findMaxValueOfBackpack() {
	int i, j;
	for (i = 0; i <= n; i++) {//모든 물건에 대해서
		for (j = 0; j <= k; j++) {//모든 가능한 무게에 대해서
			if (i == 0 || j == 0) {//물건이 없거나, 무게가 0일때는 아무것도 고르지 않음
				dp[i][j] = 0;
			}
			else if (weight[i - 1] <= j) {//담을 수 있을 때
				dp[i][j] = Max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
				//해당 물건를 담고, 해당 무게를 뺀 나머지 가방을 구성할 때 가치 VS 해당 물건을 담지 않고 나머지 물건으로 가방을 구성한 가치
			}
			else {//담을 수 없을 때
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][k];
}

int Max(int a, int b) {
	return a > b ? a : b;
}
