#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//���� �Ҵ� �� �Է�
int findSum(int);
//����� �� ��ȯ. n�� ����� ��� : (n-1)+1 + (n-2)+2 + (n-3)+3
void finish();
//���� ����

int n;
int* list;

int main() {
	init();
	finish();
	
	return 0;
}

void init() {
	int i,input;
	scanf("%d", &n);
	list = (int*)calloc(11, sizeof(int));
	list[1] = 1;
	list[2] = 2;
	list[3] = 4;
	for (i = 0; i < n; i++) {
		scanf("%d", &input);
		printf("%d\n", findSum(input));
	}
}

void finish() {
	free(list);
}

int findSum(int a) {
	if (list[a] != 0) {
		return list[a];
	}
	list[a] = findSum(a-3)+findSum(a-2)+findSum(a-1);
	return list[a];
}