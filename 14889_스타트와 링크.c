#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է� �� ���� �Ҵ�
void finish();
//���� ����
void backtracking(int, int);
//��Ʈ��ŷ�� ����Ͽ� ���� ����
void findMinValue();
//�� �ɷ�ġ�� �����Ͽ� �ɷ�ġ ������ �ּҰ��� ã��

int n;//���� ��
int** list;//���� �ɷ�ġ
int* team;//�� ����
int min = 1000000;//�ɷ�ġ ������ �ּҰ�

int main() {
	init();
	backtracking(0, 0);
	printf("%d", min);
	finish();

	return 0;
}

void backtracking(int start, int depth) {
	int i;
	if (depth == n / 2) {//���� �� ä������ ��
		findMinValue();//�ɷ�ġ ���̸� ���
		return;
	}
	for (i = start + 1; i <= n; i++) {//���� ���� �������
		team[i] = 1;//i���� ����� 1���� ���
		backtracking(i, depth + 1);//���� ����� ��
		team[i] = 0;//i��° ����� 0���� ���
	}
}

void findMinValue() {
	int i, j, t1 = 0, t2 = 0, m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {//��� ������ ����
			if (i == j) {//���� ������ ���� ��
				continue;
			}
			if (team[i] == 0 && team[j] == 0) {//�Ѵ� 0���� ��
				t1 += list[i][j];
			}
			else if (team[i] != 0 && team[j] != 0) {//�Ѵ� 1���� ��
				t2 += list[i][j];
			}
		}
	}

	if (t1 > t2) {
		m = t1 - t2;
	}
	else {
		m = t2 - t1;
	}
	if (m < min) {//�ּҰ��̶�� 
		min = m;//����
	}
}

void init() {
	int i, j;
	scanf("%d", &n);
	list = (int**)malloc((n + 1) * sizeof(int*));
	team = (int*)calloc(n + 1, sizeof(int));

	for (i = 1; i <= n; i++) {
		list[i] = (int*)malloc((n + 1) * sizeof(int));
		for (j = 1; j <= n; j++) {
			scanf("%d", &list[i][j]);
		}
	}
}

void finish() {
	int i;
	for (i = 1; i <= n; i++) {
		free(list[i]);
	}
	free(list);
	free(team);
}