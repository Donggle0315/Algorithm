#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void push(int);
int deleteq();
int isEmpty();
void minHeap();
void finish();

int n;
int* heap;//��
int numOfData;//���� ������ ����


int main() {
	init();
	minHeap();
	finish();

	return 0;
}

void init() {
	scanf("%d", &n);
	heap = (int*)malloc((n + 1) * sizeof(int));
	numOfData = 0;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		push(k);
	}
}

void finish() {
	free(heap);
}

void minHeap() {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int a = deleteq();
		int b = deleteq();
		sum += (a + b);
		push(a + b);
	}
	printf("%d", sum);
}

void push(int data) {
	int i = ++numOfData;//���� ������ ���� ++, ������ ���Ҹ� i�� ����
	while ((i != 1) && data < heap[i / 2]) {//��Ʈ ��尡 �ƴϰų� �Է¹��� data�� �� ������
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
	data = heap[1];//��ȯ�� ���� ���� ��
	temp = heap[numOfData--];//������ ���� ����
	parent = 1;
	child = 2;
	while (child <= numOfData) {//������ ������
		if ((child < numOfData) && heap[child] > heap[child + 1]) {//������ �ڽ��� ���� �ְ�, ������ �ڽ��� ���� �� ������
			child++;//������ �ڽ����� �̵�
		}
		if (temp <= heap[child]) {//temp�� child������ �۾Ƽ� ���� ��ġ�� ����
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
	if (numOfData == 0) {
		return 1;
	}
	return 0;
}