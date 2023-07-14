#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է� �� �ʱⰪ ����
int countSum();
//����� �� ��ȯ

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
	for (i = 0; i <=n; i++) {//i�� �ϳ��� �������� ����� ���� ������ 1����
		dp[0][i] = 1;
	}
	for (i = 0; i < k; i++) {//0�� i���� �������� ����� ���� ������ 1����
		dp[i][0] = 1;
	}
}

int countSum() {
	int i, j;
	for (i = 1; i < k; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000000;
			//i+1���� ���� j�� ����� ����� ���� dp[i-1][j]�� ����� ����� ���� 0�� ���ϴ� ��� & dp[i][j-1]�� �ϳ��� ���� �ٲپ� j�� ����� ���
		}
	}
	return dp[k-1][n];
}