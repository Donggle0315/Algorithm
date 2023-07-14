#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
int findUseCoin();

int n, k;
int coin[100] = { 0 };
int value[100001] = { 0 };


int main() {
	init();
	printf("%d", findUseCoin());
	
	return 0;
}

void init() {
	int i;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	value[0] = 1;//0���� ����� ����� �� 1����
}

int findUseCoin() {
	int i,j;
	for (i = 0; i < n; i++) {//��� ������ ���ؼ�
		for (j = coin[i]; j <= k; j++) {//�������� ����� �ִ� ����� ��
			value[j] += value[j - coin[i]];//���� �������θ� ����� ����� �� + ���� ������ ���ؼ� ����� ����� ��
		}
	}

	return value[k];
}