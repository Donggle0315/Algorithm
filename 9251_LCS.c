#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
//�� ���ڿ� �Է�
int findLCSLen();
//�������κм����� ã�Ƽ� �� ���̸� ��ȯ
int Max(int, int);
//ū ���� ��ȯ


char str1[1001];
char str2[1001];
int dp[1001][1001] = { 0 };


int main() {
	init();
	printf("%d", findLCSLen());


	return 0;
}

void init() {
	scanf("%s", str1);
	scanf("%s", str2);
	
}

int findLCSLen() {
	int i, j,max=0;
	for (i = 1; i <= strlen(str1); i++) {
		for (j = 1; j <= strlen(str2); j++) {
			if (str1[i-1] == str2[j-1]) {//�� ���ڰ� ���ٸ�
				dp[i][j] = dp[i - 1][j - 1] + 1;//���� dp�� 1�� ������
			}
			else {//�ٸ��ٸ�
				dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);//���� dp�� ū ���� ����
			}
			if (dp[i][j] > max) {//�ִ� ã��
				max = dp[i][j];
			}
		}
	}
	return max;
}

int Max(int a, int b) {
	return a > b ? a : b;
}