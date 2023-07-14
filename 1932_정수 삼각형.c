#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է�
int findMaxSumDP();
//DP�� �� ĭ���� �ִ� �������� �迭 dp�� ������ ��, �������ٿ��� ���� ū ���� ��ȯ
int Max(int, int);
//�� �� �� ū �� ��ȯ

int input[500][500];//�Է� ����
int dp[500][500];//���� �� ����
int n;

int main() {
	init();
	printf("%d", findMaxSumDP());

	return 0;
}

void init() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &input[i][j]);
		}
	}
}

int findMaxSumDP() {
	int i, j;
	int max;
	dp[0][0] = input[0][0];//�ʱⰪ
	for (i = 1; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0) {//���� ó���� ������ ���� �ִ� ���� �����־�� �ϴ� ����
				dp[i][j] = dp[i - 1][j] + input[i][j];
			}
			else {//���� ��([i-1][j-1]�� ������ ��([i-1][j]) �� ū ���� ������ ���� ���Ͽ� ����
				dp[i][j] = Max(dp[i - 1][j - 1], dp[i - 1][j]) + input[i][j];
			}
		}
	}
	max = dp[n - 1][0];
	for (i = 1; i < n; i++) {
		if (dp[n - 1][i] > max) {//������ �ٿ��� �ִ밪�� max�� ����
			max = dp[n - 1][i];
		}
	}
	return max;
}


int Max(int a, int b) {
	return a > b ? a : b;
}