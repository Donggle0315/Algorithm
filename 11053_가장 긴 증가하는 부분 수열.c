#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է�
int findLIS();
//�ش� ���κ��� LIS�� ã�� DP�� �����ϰ� �ִ밪 ��ȯ

int n;
int input[1000];//�Է�
int dp[1000];//�ش� ��ġ������ LIS�� ����


int main() {
	init();
	printf("%d", findLIS());

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
}

int findLIS() {
	int i,j;
	int max=1,tmp;
	if (n == 1) {
		return 1;
	}
	dp[n - 1] = 1;//������ ���� ������ 1
	for (i = n - 2; i >= 0; i--) {//�ڿ��� ���� ����
		tmp = 0;//I��°���� ū ��� �� ���� �� ������ ����
		for (j = i + 1; j < n; j++) {//I��° �ں���
			if (input[i] >= input[j]) {//�� ���� ���� ������
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