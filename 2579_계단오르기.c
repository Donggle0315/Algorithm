	#define _CRT_SECURE_NO_WARNINGS

	#include <stdio.h>
	#include <stdlib.h>

	void init();
	//���� �Ҵ� �� �Է�
	void finish();
	//���� ����
	int findMaxScore();
	//���� ������ ū �� ��ȯ
	int Max(int, int);
	//�� �� �� ū �� ��ȯ

	int n;
	int* list;//�� ����� ���� ����
	int* dp;//����� �ִ� ���� ����

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
			//i��° ĭ�� ������ 1. i-1����� ���, i-3����� ��°�(i-2�� ������ 3ĭ �����̹Ƿ� ������ i-3�� ��ƾ���) 2. i-2������� ��ĭ �������� ��
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
		//1,2,3��° ����� ����Ͽ� �ʱⰪ ����
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