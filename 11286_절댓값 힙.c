#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int data;
	int sign;
}node;

void init();
//동적 배열 할당
void push(int);
//수를 heap의 적절한 위치에 삽입
int deleteq();
//heap에서 가장 작은 수를 반환
int isEmpty();
//heap이 비었으면 1을, 아니면 0을 반환
void absHeap();
//횟수만큼 수를 입력받아 deleteq, push 실행
void finish();
//동적 해제

int n;
node* heap;//힙
int numOfData;//힙의 원소의 개수


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
			printf("%d\n", deleteq());//빈 원소이면 0을 반환
		}
		else {
			push(input);
		}
	}
}

void push(int data) {
	int i = ++numOfData;//힙의 원소의 개수 ++, 마지막 원소를 i로 저장
	int num = abs(data);//절댓값
	int sign=data/num;//부호
	while ((i != 1) && num <= heap[i / 2].data) {//루트 노드가 아니거나 입력받은 data가 더 작을때
		if (num == heap[i / 2].data && sign >= heap[i / 2].sign) {//부모와 절대값이 같지만 부호가 크거나 같으면 그만 올라가야함
			break;
		}
		heap[i].data = heap[i / 2].data;//부모 노드의 값을 자식노드로 옮김
		heap[i].sign = heap[i / 2].sign;//부모 노드의 부호를 자식노드로 옮김
		i /= 2;//부모 노드로 올라감
	}
	heap[i].data = num;//해당 위치에 절대값 삽입
	heap[i].sign = sign;//해당 위치에 부호 삽입
}

int deleteq() {
	int parent, child;
	int data, temp,sign;
	if (isEmpty() == 1) {//힙에 원소가 없다면
		return 0;
	}
	data = heap[1].data*heap[1].sign;//반환할 가장 작은 수
	temp = heap[numOfData].data;//마지막 수의 절대값
	sign = heap[numOfData--].sign;//마지막 수의 부호
	parent = 1;
	child = 2;
	while (child <= numOfData) {//마지막 노드까지
		if ((child < numOfData) && heap[child].data >= heap[child + 1].data) {//오른쪽 자식의 값이 있고, 오른쪽 자식의 값이 더 작을때
			if (heap[child].data == heap[child + 1].data && heap[child].sign <= heap[child + 1].sign) {//두 자식의 절댓값은 같지만 왼쪽 자식이 더 작다면
				child--;//왼쪽 자식을 선택해야하므로 child(-1+1=0)
			}
			child++;//오른쪽 자식으로 이동
		}
		if (temp < heap[child].data) {//temp가 child값보다 작아서 현재 위치에 저장
			break;
		}
		if (temp == heap[child].data && sign <= heap[child].sign) {//두 절대값이 같지만 자식의 부호가 크거나 같다면 그만 내려가야함
			break;
		}
		heap[parent] = heap[child];//자식으로 내려감
		parent = child;
		child *= 2;
	}
	heap[parent].data = temp;//해당 자리에 마지막원소의 절대값 temp저장
	heap[parent].sign = sign;//해당 자리에 마지막 원소의 부호 저장
	return data;//가장 작은 값 반환
}

int isEmpty() {
	if (numOfData == 0) {
		return 1;
	}
	return 0;
}