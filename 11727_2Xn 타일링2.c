#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//���� �迭 �Ҵ� �� �Է�
int FillTile(int);
//Ÿ���� ���� ��ȯ. Ÿ���� ��� ����� ���� n-2���� ��� 2*1 Ÿ�� 2�� Ȥ�� 2*2Ÿ�� �ϳ��� �߰��ϴ� ����, n-1���� ��� 1*2 Ÿ�� �ϳ��� �߰��ϴ� ���
void finish();//��������

int n;
int* list;

int main() {
	init();
	printf("%d", FillTile(n));
	finish();

	return 0;
}


void init() {
	scanf("%d", &n);
	list = (int*)calloc(n+1, sizeof(int));
	list[0] = 1;
	list[1] = 1;
}

int FillTile(int a) {
	int n1, n2;
	if (a == 1) {//�ϳ��� ���
		return 1;
	}
	if (list[a - 1] != 0) {//����� ����� �����
		n2 = list[a - 1];
	}
	else {//������� ���� ����� �����
		n2=FillTile(a - 1);//n-1�� ����� �� ����� ���� ����
		list[a - 1] = n2;//�迭�� ����
	}
	if (list[a - 2] != 0) {//����� ����� �����
		n1 = list[a - 2];
	}
	else {//������� ���� ����� �����
		n1 = FillTile(a - 2);//n-2�� ����� �� ����� ���� ����
		list[a - 2] = n1;//�迭�� ����
	}
	list[a] = (n1*2 + n2)%10007;//�� ����� ���� ���Ͽ� 10007�� ������ ����. n1�� 2*1 2�� Ȥ�� 2*2 �ϳ��� �� �� �����Ƿ� 2�� ����
	return list[a];
}


void finish() {
	free(list);
}
