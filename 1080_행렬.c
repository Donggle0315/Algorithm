#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//���� �Ҵ� �� �Է�
void finish();
//���� ����
void reverseOri(int, int);
//�Է� ���� ������ 3*3��ŭ reverse
int checking();
//�迭�� ���Ұ� �ٸ��� �ش� �ε����� 3*3��ŭ reverse, ori�� ans�� ���ٸ� reverse�� Ƚ�� ��ȯ
int isEqual();
//ori�� ans�� ������ 1, �ٸ��� -1 ��ȯ

int n, m;
int** ori;
int** res;

int main(){
	init();
	printf("%d", checking());
	finish();

	return 0;
}

void init() {
	int i,j;
	char* str;
	scanf("%d %d", &n, &m);
	ori = (int**)malloc(n * sizeof(int*));
	res = (int**)malloc(n * sizeof(int*));
	str = (char*)malloc((m + 1) * sizeof(int));
	for (i = 0; i < n; i++) {
		ori[i] = (int*)malloc(m * sizeof(int));
		res[i] = (int*)malloc(m * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		for (j = 0; j < m; j++) {
			ori[i][j] = str[j] - '0';
		}
	}
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		for (j = 0; j < m; j++) {
			res[i][j] = str[j] - '0';
		}
	}
	free(str);
}

void finish() {
	int i;
	for (i = 0; i < n; i++) {
		free(ori[i]);
		free(res[i]);
	}
	free(ori);
	free(res);
}

void reverseOri(int r, int c) {
	int i, j;
	for (i = r; i < r + 3; i++) {//r,c�� �������� 3*3��ŭ reverse
		for (j = c; j < c + 3; j++) {
			if (ori[i][j] == 0) {
				ori[i][j] = 1;
			}
			else {
				ori[i][j] = 0;
			}
		}
	}
}

int checking() {
	int num = 0;//������ Ƚ��
	int i, j;
	if (n < 3 || m < 3) {
		if (isEqual() == 1) {//3*3 �̸������� �迭�� ���ٸ�
			return 0;//0�� ������
		}
		return -1;//�Ұ���
	}
	for (i = 0; i < n - 2; i++) {
		for (j = 0; j < m - 2; j++) {
			if (ori[i][j] != res[i][j]) {//i,j �迭�� ���� �ٸ��ٸ�
				reverseOri(i, j);//i,j�� �������� reverse
				num++;//������ Ƚ�� ++
				if (isEqual() == 1) {//�迭�� �������ٸ�
					return num;
				}
			}
		}
	}
	return -1;//������ �ٲ�µ��� �迭�� �ٸ��ٸ�
}

int isEqual() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (ori[i][j] != res[i][j]) {//�迭�� �ٸ��ٸ�
				return -1;
			}
		}
	}
	return 1;//�迭�� ���ٸ�
}