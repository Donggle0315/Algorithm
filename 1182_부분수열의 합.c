#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//���� �Ҵ� �� �Է�
void finish();
//���� ����
void backtracking(int,int);
//��Ʈ��ŷ�� �̿��� �κм����� ����, �κм����� ���� s�� ��� count++
int sum(int);
//�κ� ������ ���� ���� ��ȯ

int n, s;//n�� ������ ����, s�� ���ϰ��� �ϴ� �κ� ������ ��
int* list;//����
int* bt;//���õ� �κ� ����
int count;//s�� �����ϴ� �κм����� ����



int main() {
	init();
	backtracking(-1,0);
	printf("%d", count);
	finish();


	return 0;
}

void backtracking(int start, int depth) {
	int i;
	if (depth == n) {//��� ���Ҹ� Ž���ߴٸ�
		return;
	}
	for (i = start + 1; i < n; i++) {//�������� ���� ���ҿ� ����
		bt[depth] = list[i];//�κм����� ����
		if (sum(depth+1) == s) {//�κм����� ���� s�� ���ٸ�
			count++;
		}
		backtracking(i, depth + 1);//���� ���Ҹ� ��
	}
}

int sum(int d) {
	int i, sum = 0;
	for (i = 0; i < d; i++) {
		sum += bt[i];
	}
	return sum;
}


void init() {
	int i;
	scanf("%d %d", &n, &s);
	list = (int*)malloc(n * sizeof(int));
	bt = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	count = 0;
}

void finish() {
	free(list);
	free(bt);
}