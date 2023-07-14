	#define _CRT_SECURE_NO_WARNINGS

	#include <stdio.h>
	#include <stdlib.h>

	void init();
	//동적 할당 및 입력
	void finish();
	//동적 해제
	int findMaxScore();
	//가장 점수가 큰 값 반환
	int Max(int, int);
	//두 수 중 큰 값 반환

	int n;
	int* list;//각 계단의 점수 저장
	int* dp;//경로의 최대 점수 저장

	int main() {
		init();
		printf("%d", findMaxScore());
		finish();

		return 0;
	}

	int Max(int a, int b) {
		return a > b ? a : b;
	}


	int findMaxScore() {
		int i;
		for (i = 3; i < n; i++) {
			dp[i] = Max(dp[i - 3] + list[i - 1] + list[i], dp[i - 2] + list[i]);
			//i번째 칸에 오려면 1. i-1계단을 밟고, i-3계단을 밟는것(i-2를 밟으면 3칸 연속이므로 무조건 i-3을 밟아야함) 2. i-2계단으로 두칸 내려가는 것
		}
		return dp[n-1];
	}

	void init() {
		int i;
		scanf("%d", &n);
		list = (int*)malloc(n * sizeof(int));
		dp = (int*)calloc(n, sizeof(int));
		for (i = 0; i < n; i++) {
			scanf("%d", &list[i]);
		}
		//1,2,3번째 경우을 계산하여 초기값 설정
		if (n >= 1) {
			dp[0] = list[0];
		}
		if (n >= 2) {
			dp[1] = Max(list[0]+list[1],list[1]);
		}
		if (n >= 3) {
			dp[2] = Max(list[0] + list[2], list[1] + list[2]);
		}
	}

	void finish() {
		free(list);
		free(dp);
	}