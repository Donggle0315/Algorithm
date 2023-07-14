#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init(int);//matrix �迭 �����Ҵ� �� ���� �Է� �� �����ϴ� �Լ�
void finish(int);//matrix �迭 �����Ҵ� �����ϴ� �Լ�
void printing();//-1,0,1�� ä���� ������ ���� ����ϴ� �Լ�
void re_counting(int, int, int);//��Ŀ� ����� ���̸� �߶� -1,0,1�θ� ä���� ������ ������ ���س��� �Լ�

int** matrix;//N*Nũ���� ���
int n1 = 0, n2 = 0, n3 = 0;//n1�� -1, n2�� 0, n3�� 1�� �̷���� ������ ����

int main() {
	int num;

	scanf("%d", &num);
	init(num);
	re_counting(0, 0, num);
	printing();
	finish(num);

	return 0;
}

void init(int num) {
	int i, j;
	matrix = (int**)malloc(num * sizeof(int*));
	for (i = 0; i < num; i++) {
		matrix[i] = (int*)malloc(num * sizeof(int));
	}
	//�����Ҵ�
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	//���� �Է� �� ����
}

void finish(int num) {
	int i;
	for (i = 0; i < num; i++) {
		free(matrix[i]);
	}
	free(matrix);
	//���� �Ҵ� ����
}

void printing() {
	printf("%d\n", n1);
	printf("%d\n", n2);
	printf("%d\n", n3);
	//���
}


void re_counting(int row, int col, int n) {//row�� col�� ���� ��ġ, n�� ��� ���� ����
	int i, j, k = matrix[row][col],new_n = n / 3, flag = 0; //k�� ����� ù ����, new_n�� ���� ����� ����, flag�� 1�϶� ��� ���� ���� �ƴ� ���, 0�϶� ��� ���� �� �� ���
	if (n == 1) { //n�� 1�̸� �˻��� �ʿ� ���� ��� ���� ��
		switch (k) {
			case -1:
				n1++;
				break;
			case 0:
				n2++;
				break;
			case 1:
				n3++;
		}
		return;//�Լ� ����
	}
	for (i = row; i < row + n; i++) {
		for (j = col; j < col + n; j++) {
			if (matrix[i][j] != k) { //���̰� ��� ���� ���� �ƴ� ���
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	if (flag == 0) { //���̰� ��� ���� �� �� ���
		switch (k) {
			case -1:
				n1++;
				break;
			case 0:
				n2++;
				break;
			case 1:
				n3++;
		}
	}
	else { // ���̰� ��� ���� ���� �ƴ� ��� 
		for (i = 0; i < 3; i++) { 
			for (j = 0; j < 3; j++) { //9����Ͽ� �Լ� ��� ȣ��
				re_counting(row + i * new_n, col + j * new_n, new_n);
			}
		}
	}
}