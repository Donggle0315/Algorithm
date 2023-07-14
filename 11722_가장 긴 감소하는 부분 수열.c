#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է�
int findLDS();
//�ش� ���κ��� LDS�� ã�� DP�� �����ϰ� �ּҰ� ��ȯ

int n;
int input[1000];//�Է�
int dp[1000];//�ش� ��ġ������ LDS�� ����


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
	dp[n - 1] = 1;//������ ���� ������ 1
	for (i = n - 2; i >= 0; i--) {//�ڿ��� ���� ����
		tmp = 0;//I��°���� ���� ��� �� ���� �� ������ ����
		for (j = i + 1; j < n; j++) {//I��° �ں���
			if (input[i] <= input[j]) {//�� ū ���� ������
				continue;
			}
			if (dp[j] > tmp) {//�ش� ���� �������� �� ��ٸ�
				tmp = dp[j];
			}
		}
		dp[i] = tmp + 1;
	}
	for (i = 0; i < n; i++) {//�ִ� ���� MAX�� ����
		if (dp[i] > max) {
			max = dp[i];
		}
	}
	return max;
}