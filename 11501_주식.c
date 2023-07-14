#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
1. ��� ��� : �ڿ� �� ���� ���� ���� ��
2. �Ĵ� ��� : �ڿ� �� ���� ���� ���� ��
3. �ƹ��͵� ���ϴ� ��� : �ֽ��� ���µ� �ڿ� ���� ���� ���� ��
*/

void init();
long long findMax();

int n;
int list[1000000];

int main() {
	int i;
	init();
	for (i = 0; i < n; i++) {
		printf("%lld\n", findMax());
	}

	return 0;
}

void init() {
	scanf("%d", &n);
}

long long findMax() {
	int num, i;
	int max = 0;
	long long money = 0;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &list[i]);
	}
	max = list[num - 1];
	for (i = num - 1; i >= 0; i--) {
		if (list[i] < max) {
			money += max - list[i];
		}
		else {
			max = list[i];
		}
	}
	
	return money;

}