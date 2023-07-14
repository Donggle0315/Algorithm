#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է�
int findMaxValueOfBackpack();
//�ִ� ��ġ�� ��ȯ
int Max(int, int);
//ū �� ��ȯ

int n, k;
int weight[100];//������ ���� ����
int value[100];//������ ��ġ ����
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
	for (i = 0; i <= n; i++) {//��� ���ǿ� ���ؼ�
		for (j = 0; j <= k; j++) {//��� ������ ���Կ� ���ؼ�
			if (i == 0 || j == 0) {//������ ���ų�, ���԰� 0�϶��� �ƹ��͵� ���� ����
				dp[i][j] = 0;
			}
			else if (weight[i - 1] <= j) {//���� �� ���� ��
				dp[i][j] = Max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
				//�ش� ���Ǹ� ���, �ش� ���Ը� �� ������ ������ ������ �� ��ġ VS �ش� ������ ���� �ʰ� ������ �������� ������ ������ ��ġ
			}
			else {//���� �� ���� ��
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][k];
}

int Max(int a, int b) {
	return a > b ? a : b;
}
