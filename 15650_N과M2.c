#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//���� �Ҵ� �� �Է�
void finish();
//���� ����
void printResult();
//�� ä������ ���
void findCombination(int);
//������������ �ߺ� ���� ���ڸ� ä������

int* result;//����� ��� �� ����
int* visited;//�湮 ����
int n, m;

int main() {

	init();
	findCombination(1);
	finish();


	return 0;
}

void init() {
	scanf("%d %d", &n, &m);
	result = (int*)malloc((m + 1) * sizeof(int));
	visited = (int*)calloc(n + 1, sizeof(int));
	result[0] = 0;
}

void finish() {
	free(result);
	free(visited);
}

void printResult() {
	int i;
	for (i = 1; i <= m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

void findCombination(int depth) {
	int i;
	if (depth == m + 1) {//�� ä������
		printResult();//���
		return;
	}
	for (i = result[depth - 1] + 1; i <= n; i++) {//���� �� ���� ������(���������� ����)
		if (visited[i] == 0) {//�湮 ���ߴٸ�
			visited[i] = 1;//�湮
			result[depth] = i;//����
			findCombination(depth + 1);//���� �� ����
			visited[i] = 0;//�湮 ��
		}
	}
}