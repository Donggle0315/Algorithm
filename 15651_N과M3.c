#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//���� �Ҵ� �� �Է�
void finish();
//���� ����
void printResult();
//�� ä������ ���
void findSequence(int);
//�ߺ� �ְ� ������ ä��

int* result;//����� ��� ����
int n, m;

int main() {

	init();
	findSequence(0);
	finish();


	return 0;
}

void init() {
	scanf("%d %d", &n, &m);
	result = (int*)malloc((m + 1) * sizeof(int));
}

void finish() {
	free(result);
}

void printResult() {
	int i;
	for (i = 0; i < m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

void findSequence(int depth) {
	int i;
	if (depth == m) {//�� ä������
		printResult();//���
		return;
	}
	for (i =1; i <= n; i++) {//�ߺ������ϹǷ� visited���� Ȯ���� �ʿ����
		result[depth] = i;//����
		findSequence(depth + 1);//���� �� Ȯ��
	}
}