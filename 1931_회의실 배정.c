#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int start;
	int end;
}node;

void init();
//���� �Ҵ� �� �Է�
void sortEnd(int, int);
//������ �ð� �������� �������� ����
void sortStart();
//������ �ð��� ���� ���, ���� �ð� �������� �������� ����
void sorts(int, int);
//�ش� ����(end���� ���� ����)�� ���� start�������� ����
int greedyCount();
//ȸ�� �ִ� ������ ����, Ƚ�� ��ȯ
void finish();
//���� ����

int n;
node* list;

int main() {
	init();
	sortEnd(0, n - 1);
	sortStart();
	printf("%d", greedyCount());
	finish();

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	list = (node*)malloc(n * sizeof(node));
	for (i = 0; i < n; i++) {
		scanf("%d %d", &list[i].start, &list[i].end);
	}
}

void finish() {
	free(list);
}

void sortEnd(int left, int right) {//������ ������ �������� ������
	int tmps, tmpe;
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2].end;
	do {
		while (list[pl].end < x) {
			pl++;
		}
		while (list[pr].end > x) {
			pr--;
		}
		if (pl <= pr) {
			tmps = list[pr].start;
			tmpe = list[pr].end;
			list[pr].start = list[pl].start;
			list[pr].end = list[pl].end;
			list[pl].start = tmps;
			list[pl].end = tmpe;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		sortEnd(left, pr);
	}
	if (pl < right) {
		sortEnd(pl, right);
	}
}

void sortStart() {//������ �ð��� ���� ������ ���� start �������� ������
	int i,now=list[0].end;
	int count = 0;
	for (i = 0; i < n; i++) {
		if (list[i].end == now) {
			count++;
		}
		else {
			sorts(i - count, i - 1);
			count = 1;
			now = list[i].end;
		}
	}
	if (count != 1) {
		sorts(i - count, i - 1);
	}
}

void sorts(int left, int right) {//�����ϴ� �ð� �������� ������
	int tmps;
	int pl = left;
	int pr = right;
	int x = list[(left + right) / 2].start;
	do {
		while (list[pl].start < x) {
			pl++;
		}
		while (list[pr].start > x) {
			pr--;
		}
		if (pl <= pr) {
			tmps = list[pr].start;
			list[pr].start = list[pl].start;
			list[pl].start = tmps;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		sorts(left, pr);
	}
	if (pl < right) {
		sorts(pl, right);
	}
}

int greedyCount() {//������ ���� ���� ������ ȸ�Ǹ� �ִ´�.
	int count = 1;
	int end = list[0].end;//ù��° ȸ�Ǵ� ���� ���� ������ ������ ����
	int idx = 0;
	int i;
	for (i = idx+1; i < n; i++) {//���ĵ� �ð��� ����
		if (list[i].start >= end) {//���� ȸ���� ���� �ð��� ������ �ð����� �ʰų� ������
			idx = i;
			end = list[i].end;
			count++;//ȸ�� ����
		}
	}
	return count++;//ȸ�� ���� ��ȯj
}