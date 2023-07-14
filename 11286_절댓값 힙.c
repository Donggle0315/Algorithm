#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int data;
	int sign;
}node;

void init();
//���� �迭 �Ҵ�
void push(int);
//���� heap�� ������ ��ġ�� ����
int deleteq();
//heap���� ���� ���� ���� ��ȯ
int isEmpty();
//heap�� ������� 1��, �ƴϸ� 0�� ��ȯ
void absHeap();
//Ƚ����ŭ ���� �Է¹޾� deleteq, push ����
void finish();
//���� ����

int n;
node* heap;//��
int numOfData;//���� ������ ����


int main() {
	init();
	absHeap();
	finish();

	return 0;
}

void init() {
	scanf("%d", &n);
	heap = (node*)malloc((n + 1) * sizeof(node));
	numOfData = 0;
}

void finish() {
	free(heap);
}

void absHeap() {
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
	int num = abs(data);//����
	int sign=data/num;//��ȣ
	while ((i != 1) && num <= heap[i / 2].data) {//��Ʈ ��尡 �ƴϰų� �Է¹��� data�� �� ������
		if (num == heap[i / 2].data && sign >= heap[i / 2].sign) {//�θ�� ���밪�� ������ ��ȣ�� ũ�ų� ������ �׸� �ö󰡾���
			break;
		}
		heap[i].data = heap[i / 2].data;//�θ� ����� ���� �ڽĳ��� �ű�
		heap[i].sign = heap[i / 2].sign;//�θ� ����� ��ȣ�� �ڽĳ��� �ű�
		i /= 2;//�θ� ���� �ö�
	}
	heap[i].data = num;//�ش� ��ġ�� ���밪 ����
	heap[i].sign = sign;//�ش� ��ġ�� ��ȣ ����
}

int deleteq() {
	int parent, child;
	int data, temp,sign;
	if (isEmpty() == 1) {//���� ���Ұ� ���ٸ�
		return 0;
	}
	data = heap[1].data*heap[1].sign;//��ȯ�� ���� ���� ��
	temp = heap[numOfData].data;//������ ���� ���밪
	sign = heap[numOfData--].sign;//������ ���� ��ȣ
	parent = 1;
	child = 2;
	while (child <= numOfData) {//������ ������
		if ((child < numOfData) && heap[child].data >= heap[child + 1].data) {//������ �ڽ��� ���� �ְ�, ������ �ڽ��� ���� �� ������
			if (heap[child].data == heap[child + 1].data && heap[child].sign <= heap[child + 1].sign) {//�� �ڽ��� ������ ������ ���� �ڽ��� �� �۴ٸ�
				child--;//���� �ڽ��� �����ؾ��ϹǷ� child(-1+1=0)
			}
			child++;//������ �ڽ����� �̵�
		}
		if (temp < heap[child].data) {//temp�� child������ �۾Ƽ� ���� ��ġ�� ����
			break;
		}
		if (temp == heap[child].data && sign <= heap[child].sign) {//�� ���밪�� ������ �ڽ��� ��ȣ�� ũ�ų� ���ٸ� �׸� ����������
			break;
		}
		heap[parent] = heap[child];//�ڽ����� ������
		parent = child;
		child *= 2;
	}
	heap[parent].data = temp;//�ش� �ڸ��� ������������ ���밪 temp����
	heap[parent].sign = sign;//�ش� �ڸ��� ������ ������ ��ȣ ����
	return data;//���� ���� �� ��ȯ
}

int isEmpty() {
	if (numOfData == 0) {
		return 1;
	}
	return 0;
}