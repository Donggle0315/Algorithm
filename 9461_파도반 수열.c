#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//���� �Ҵ� �� �Է�
long long findLength(int);
//�ش� ���� ���� ��ȯ. ��ȭ�� a(n)=a(n-2)+a(n-3)
void finish();
//���� ����

int t;
long long* list;

int main() {
	init();
	finish();

	return 0;
}

void init() {
	int i,n;
	scanf("%d", &t);
	list = (long long*)calloc(101, sizeof(long long));
	list[1] = 1;
	list[2] = 1;
	list[3] = 1;
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%lld\n", findLength(n));
	}
}

long long findLength(int n) {
	if (list[n] != 0) {//�̹� ���� ������
		return list[n];
	}
	list[n] = findLength(n - 2) + findLength(n - 3);
	return list[n];
}

void finish() {
	free(list);
}