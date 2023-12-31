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
int* heap;//힙
int numOfData;//힙의 원소의 개수


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
	int i = ++numOfData;//힙의 원소의 개수 ++, 마지막 원소를 i로 저장
	while ((i != 1) && data < heap[i / 2]) {//루트 노드가 아니거나 입력받은 data가 더 작을때
		heap[i] = heap[i / 2];//부모 노드의 값을 자식노드로 옮김
		i /= 2;//부모 노드로 올라감
	}
	heap[i] = data;//해당 위치에 data 삽입
}

int deleteq() {
	int parent, child;
	int data, temp;
	if (isEmpty() == 1) {//힙에 원소가 없다면
		return 0;
	}
	data = heap[1];//반환할 가장 작은 수
	temp = heap[numOfData--];//마지막 수를 저장
	parent = 1;
	child = 2;
	while (child <= numOfData) {//마지막 노드까지
		if ((child < numOfData) && heap[child] > heap[child + 1]) {//오른쪽 자식의 값이 있고, 오른쪽 자식의 값이 더 작을때
			child++;//오른쪽 자식으로 이동
		}
		if (temp <= heap[child]) {//temp가 child값보다 작아서 현재 위치에 저장
			break;
		}
		heap[parent] = heap[child];//자식으로 내려감
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;//해당 자리에 마지막원소였던 temp저장
	return data;//가장 큰 값 반환
}

int isEmpty() {
	if (numOfData == 0) {
		return 1;
	}
	return 0;
}