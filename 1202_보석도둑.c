#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void mergeSortJewel(int, int);
void mergeSortBackpack(int, int);
void finish();
void playSteal();
void push(int);
int deleteq();
int isEmpty();

int n, k;
int** jewel;
int* backpack;
int** temp;
int* temp2;
long long sum;
int* heap;
int numOfData;


int main() {
	init();
	playSteal();
	printf("%lld", sum);
	finish();

	return 0;
}

void playSteal() {
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && jewel[idx][0] <= backpack[i]) {
			push(jewel[idx++][1]);
		}
		if (isEmpty() == 0) {
			sum += deleteq();
		}
	}
}

void push(int data) {
	int i = ++numOfData;//���� ������ ���� ++, ������ ���Ҹ� i�� ����
	while ((i != 1) && data > heap[i / 2]) {//��Ʈ ��尡 �ƴϰų� �Է¹��� data�� �� Ŭ��
		heap[i] = heap[i / 2];//�θ� ����� ���� �ڽĳ��� �ű�
		i /= 2;//�θ� ���� �ö�
	}
	heap[i] = data;//�ش� ��ġ�� data ����
}

int deleteq() {
	int parent, child;
	int data, temp;
	if (isEmpty() == 1) {//���� ���Ұ� ���ٸ�
		return 0;
	}
	data = heap[1];//��ȯ�� ���� ū ��
	temp = heap[numOfData--];//������ ���� ����
	parent = 1;
	child = 2;
	while (child <= numOfData) {//������ ������
		if ((child < numOfData) && heap[child] < heap[child + 1]) {//������ �ڽ��� ���� �ְ�, ������ �ڽ��� ���� �� Ŭ��
			child++;//������ �ڽ����� �̵�
		}
		if (temp >= heap[child]) {//temp�� child������ Ŀ�� ���� ��ġ�� ����
			break;
		}
		heap[parent] = heap[child];//�ڽ����� ������
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;//�ش� �ڸ��� ���������ҿ��� temp����
	return data;//���� ū �� ��ȯ
}

int isEmpty() {
	if (numOfData==0) {
		return 1;
	}
	return 0;
}

void init() {
	scanf("%d %d", &n, &k);
	jewel = (int**)malloc(n * sizeof(int*));
	temp = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		temp[i] = (int*)malloc(2 * sizeof(int));
		jewel[i] = (int*)malloc(2 * sizeof(int));
		scanf("%d %d", &jewel[i][0], &jewel[i][1]);
	}
	temp2 = (int*)malloc(k * sizeof(int));
	backpack = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++) {
		scanf("%d", &backpack[i]);
	}

	mergeSortJewel(0, n - 1);
	mergeSortBackpack(0, k - 1);

	sum = 0;
	
	heap = (int*)malloc((n + 1) * sizeof(int));
	numOfData = 0;
}

void finish() {
	for (int i = 0; i < n; i++) {
		free(jewel[i]);
		free(temp[i]);
	}
	free(jewel);
	free(temp);
	free(backpack);
	free(temp2);
	free(heap);
}

void mergeSortJewel(int left, int right) {
	if (left >= right) {
		return;
	}

	int middle = (left + right) / 2;
	mergeSortJewel(left, middle);
	mergeSortJewel(middle + 1, right);

	for (int i = left, l = left, r = middle + 1; l != middle + 1 || r != right + 1; i++) {
		if (r != right + 1 && l <= middle && jewel[l][0] < jewel[r][0] || r == right + 1) {
			temp[i][0] = jewel[l][0];
			temp[i][1] = jewel[l++][1];
		}
		else {
			temp[i][0] = jewel[r][0];
			temp[i][1] = jewel[r++][1];
		}
	}

	for (int i = left; i <= right; i++) {
		jewel[i][0] = temp[i][0];
		jewel[i][1] = temp[i][1];
	}
}

void mergeSortBackpack(int left, int right) {
	if (left >= right) {
		return;
	}

	int middle = (left + right) / 2;
	mergeSortBackpack(left, middle);
	mergeSortBackpack(middle + 1, right);

	for (int i = left, l = left, r = middle + 1; l != middle + 1 || r != right + 1; i++) {
		if (r != right + 1 && l <= middle && backpack[l] < backpack[r] || r == right + 1) {
			temp2[i] = backpack[l++];
		}
		else {
			temp2[i] = backpack[r++];
		}
	}

	for (int i = left; i <= right; i++) {
		backpack[i] = temp2[i];
	}
}