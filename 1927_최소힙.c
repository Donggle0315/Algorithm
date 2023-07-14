#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//���� �迭 �Ҵ�
void push(int);
//���� heap�� ������ ��ġ�� ����
int deleteq();
//heap���� ���� ���� ���� ��ȯ
int isEmpty();
//heap�� ������� 1��, �ƴϸ� 0�� ��ȯ
void minHeap();
//Ƚ����ŭ ���� �Է¹޾� deleteq, push ����
void finish();
//���� ����

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
}

void finish() {
	free(heap);
}

void minHeap() {
	int i, input;
	for (i = 0; i < n; i++) {
		scanf("%d", &input);
		if (input == 0) {
			printf("%d\n", deleteq());//�� �����̸� 0�� ��ȯ
		}
		else {
			push(input);
		}
	}
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