#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init();
//���� �迭 �Ҵ� �� �Է�
void finish();
//���� ����
void qsorting(int*,int, int);
//�Է����� ���� �迭 �������� ����
void findDistance();
//������ �Ÿ��� �����Ͽ� ���밪�� dist �迭�� ����
int findMinSum();
//���� �� �Ÿ��� ���߱�-1�� ��ŭ �A ��, �Ÿ��� �� ��ȯ

int n, k;
int* list;
int* dist;



int main() {
	init();
	qsorting(list,0, n - 1);
	findDistance();
	qsorting(dist, 0, n - 2);

	printf("%d", findMinSum());
	finish();

	return 0;
}

void init() {
	int i;
	scanf("%d", &n);
	scanf("%d",&k);
	list = (int*)malloc(n * sizeof(int));
	dist = (int*)malloc((n-1) * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
}

void qsorting(int* arr, int left, int right) {
	int pl = left;
	int pr = right;
	int x = arr[(left + right) / 2];
	int tmp;
	do {
		while (arr[pl] < x) {
			pl++;
		}
		while (arr[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			tmp = arr[pl];
			arr[pl] = arr[pr];
			arr[pr] = tmp;
			pr--;
			pl++;
		}
	} while (pl <= pr);
	if (pl < right) {
		qsorting(arr,pl, right);
	}
	if (left < pr) {
		qsorting(arr,left, pr);
	}
}

void findDistance() {
	int i;
	for (i = 0; i < n - 1; i++) {
		dist[i] = abs(list[i] - list[i + 1]);//���� ������ �Ÿ��� ����
	}
}

int findMinSum() {
	int i, sum = 0;
	if (n == k) {
		return 0;//���� ���� ���߱� ���� ������ ���� ��ġ�� ���߱��� ������ ��
	}
	for (i = 0; i < n-k; i++) {//���� ������ ����-(���߱�-1)�� �� 
		sum += dist[i];
	}
	return sum;
}

void finish() {
	free(list);
	free(dist);
}