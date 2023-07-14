#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Plus(int, int);
//���� 
int Minus(int, int);
//����
int Multiply(int, int);
//����
int Div(int, int);
//������
void init();
//���� �Ҵ� �� �Է�
void finish();
//���� ����
void backtracking(int);
//��Ʈ��ŷ�� �̿��Ͽ� ����
void isMaxMin();
//���� ���� ��� �� �ִ� �ּڰ����� Ȯ��

int n;//������ ����
int* num;//���� �Է�
int* res;//���� ���
int oper[4] = { 0 };//������ ����
int min, max;//�ִ�, �ּҰ�

int main() {
	init();
	backtracking(0);
	printf("%d\n%d", max, min);
	finish();

	return 0;
}

void isMaxMin() {
	if (res[n - 1] > max) {
		max = res[n - 1];
	}
	if (res[n - 1] < min) {
		min = res[n - 1];
	}
}

void backtracking(int depth) {
	int i;
	if (depth == n-1) {//������ ����
		isMaxMin();//�ִ� �ּ� ����
		return;
	}
	for (i = 0; i < 4; i++) {//��� �����ڿ� ����
		if (oper[i] == 0) {//�����ִ� �����ڰ� ������
			continue;
		}
		oper[i]--;//�ش� ������ ���
		switch (i) {
			case 0://����
				res[depth + 1] = Plus(res[depth], num[depth + 1]);//���� ���� ����� ���� ���� �����Ͽ� �������� ����
				backtracking(depth + 1);//���� ����
				break;
			case 1://����
				res[depth + 1] = Minus(res[depth], num[depth + 1]);//���� ���� ����� ���� ���� �����Ͽ� �������� ����
				backtracking(depth + 1);//���� ����
				break;
			case 2://����
				res[depth + 1] = Multiply(res[depth], num[depth + 1]);//���� ���� ����� ���� ���� �����Ͽ� �������� ����
				backtracking(depth + 1);//���� ����
				break;
			case 3://������
				res[depth + 1] = Div(res[depth], num[depth + 1]);//���� ���� ����� ���� ���� �����Ͽ� �������� ����
				backtracking(depth + 1);//���� ����
				break;
		}
		oper[i]++;//�ش� ������ ��� �Ϸ�
	}
}

void init() {
	int i;
	scanf("%d", &n);
	num = (int*)malloc(n * sizeof(int));
	res = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	res[0] = num[0];
	min = 1000000001;
	max = -1000000001;
}

void finish() {
	free(num);
}


int Plus(int a, int b) {
	return a + b;
}

int Minus(int a, int b) {
	return a - b;
}

int Multiply(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	if (a < 0) {
		return -(a * (-1) / b);
	}
	return a / b;
}
