#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//입력
int findLDS();
//해당 수로부터 LDS를 찾아 DP에 저장하고 최소값 반환

int n;
int input[1000];//입력
int dp[1000];//해당 위치에서의 LDS값 저장


int main() {
	init();
	printf("%d", findLDS());

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
}

int findLDS() {
	int i, j;
	int max = 1, tmp;
	if (n == 1) {
		return 1;
	}
	dp[n - 1] = 1;//마지막 경우는 무조건 1
	for (i = n - 2; i >= 0; i--) {//뒤에서 부터 조사
		tmp = 0;//I번째보다 작은 경우 중 가장 긴 수열의 길이
		for (j = i + 1; j < n; j++) {//I번째 뒤부터
			if (input[i] <= input[j]) {//더 큰 수가 나오면
				continue;
			}
			if (dp[j] > tmp) {//해당 수를 기준으로 더 길다면
				tmp = dp[j];
			}
		}
		dp[i] = tmp + 1;
	}
	for (i = 0; i < n; i++) {//최대 길이 MAX에 저장
		if (dp[i] > max) {
			max = dp[i];
		}
	}
	return max;
}