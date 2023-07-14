#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է� �� ���� �Ҵ�
void finish();
//���� ����
void printResult();
//m�� ��ŭ ä������ ����� ���� ���
void findPermutation(int);
//��͸� ���� ��Ʈ��ŷ���� ������ ä��

int* result;//����� �� ����
int* visited;//�湮 ���� ����
int n, m;

int main() {

	init();
	findPermutation(0);
	finish();


	return 0;
}

void init() {
	scanf("%d %d", &n, &m);
	result = (int*)malloc(m * sizeof(int));
	visited = (int*)calloc(n + 1, sizeof(int));
}

void finish() {
	free(result);
	free(visited);
}

void printResult() {
	int i;
	for (i = 0; i < m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

void findPermutation(int depth) {
	int i;
	if (depth == m) {//�� ä������ ���
		printResult();
		return;
	}
	for (i = 1; i <= n; i++) {//1���� n������ �� ��
		if (visited[i] == 0) {//�湮���� �ʾҴٸ�
			visited[i] = 1;//�湮�ϰ�
			result[depth] = i;//�����ϰ�
			findPermutation(depth + 1);//���� ������ ���
			visited[i] = 0;//�湮�� ����
		}
	}
}