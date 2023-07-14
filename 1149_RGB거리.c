#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է�
int dp_house();
//dp�� �̿��Ͽ� �ּҰ��� ã��. ���ٿ��� �� ĭ���� �ּҰ� �Ǵ� ���� dp�� �����Ͽ�, ������ �ٿ��� �ּҰ� ��ȯ
int Min(int, int);
//�� ���� �� ��ȯ

int house[1000][3];//�Է��� �� ����
int dp[1000][3];//��������� �ּ� ������ ����
int num;

int main() {
	init();
	dp_house();
	printf("%d", dp_house());

	return 0;
}

void init() {
	int i;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
	}
}

int dp_house() {
	int i;
	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];
	for (i = 1; i < num; i++) {
		//���� ��ġ�� �����鼭 �� ���� ���� ������ ���� ���Ͽ� ������
		dp[i][0] = Min(dp[i - 1][1], dp[i-1][2]) + house[i][0];
		dp[i][1] = Min(dp[i - 1][0], dp[i-1][2]) + house[i][1];
		dp[i][2] = Min(dp[i - 1][0], dp[i-1][1]) + house[i][2];
	}
	return Min(Min(dp[num - 1][0], dp[num - 1][1]), dp[num - 1][2]);//������ ������ �� �� �ּҰ��� ��ȯ
}

int Min(int a, int b) {
	return a < b ? a : b;
}
