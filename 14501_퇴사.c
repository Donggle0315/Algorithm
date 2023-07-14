#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void init();
//�Է�
int makeSchedule();
//�ִ� �̵��� ����ϰ� �ִ� �̵氪 ��ȯ

int list[16][2] = { 0 };//�ɸ��� ���� ���� ����
int dp[16] = { 0 };//i��° ������ ������ �� �ִ�� �� �� �ִ� �� ����
int n;

int main() {
	init();
	printf("%d", makeSchedule());

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &list[i][0], &list[i][1]);
	}
}

int makeSchedule() {
	int i;
	dp[n] = 0;
	for (i = n - 1; i >= 0; i--) {//�������� ����
		if (i + list[i][0] > n) {//ȸ�翡 ���� ���� ��� �Ұ�
			dp[i] = dp[i+1];//�������� ����
		}
		else {//������ �������� ȸ�翡�� ����
			if (dp[i+1]-dp[i+list[i][0]] < list[i][1]) {//�̳� ���� �ϴ°� �̵�
				dp[i] = list[i][1] + dp[i + list[i][0]];//�����ϴ� ���� �� + ���� ���� ������ �� �� ��
			}
			else {
				dp[i] = dp[i + 1];//�������� ����
			}
		}
	}
	return dp[0];

}