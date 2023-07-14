#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void setNum();
void finish();
void sort(int, int);

int* num;
int n;

/*
�� �ڸ����� ���� ���Ѵ� �ڸ��� ���� 10,100,1000 ������
������������ �����Ͽ� 9���� �ο�
�� ���ϱ�
*/

int main() {
	init();
	sort(0,25);
	setNum();
	finish();

	return 0;
}

void init() {
	int i,j,pow;
	char* str = (char*)malloc(15 * sizeof(char));
	scanf("%d", &n);
	num = (int*)calloc(26, sizeof(int));

	for (i = 0; i < n; i++) {
		pow = 1;//�ڸ���
		scanf("%s", str);//���� �ϳ� �Է�
		for (j = strlen(str)-1; j>=0; j--) {//���� �ڸ�������
			if (str[j] >= 'A' && str[j] <= 'Z') {//���ĺ��̶��
				num[str[j] - 'A'] += pow;//�ش� �ڸ��� ��ŭ ����ġ
				pow *= 10;//���� �ڸ���
			}
		}
	}
	free(str);
}

void sort(int left, int right) {//����ġ�� ������������ ����
	int pl = left;
	int pr = right;
	int x = num[(left + right) / 2];
	int tmp;
	do {
		while (num[pl] < x) {
			pl++;
		}
		while (num[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			tmp = num[pl];
			num[pl] = num[pr];
			num[pr] = tmp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (pl < right) {
		sort(pl, right);
	}
	if (pr > left) {
		sort(left, pr);
	}
}

void setNum() {//����ġ��ŭ �ִ� 10���� ���� ����ġ�� ū ������� 9���� ���ؼ� ����
	int i, sum = 0, s = 9;
	for (i = 0; i <10; i++) {
		sum += (s * num[25-i]);
		s--;
	}
	printf("%d", sum);
}

void finish() {
	free(num);
}