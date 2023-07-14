#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void push(int);
int pop();
int top();
int isEmpty();
void laser();
void print();
int* stack;
int front;
int n;
int* list;
int* towerReceive;


int main() {
	init();
	laser();
	print();
	finish();

	return 0;
}

void laser() {
	for (int i = n - 1; i >= 0; i--) {
		if(isEmpty()==0&& list[top()]<=list[i]) {//같거나 커서 해당 건물에 레이저를 쏘는 건물이 존재
			while (isEmpty() == 0&&list[top()] <= list[i]) {
				towerReceive[pop()] = i+1;
			}
		}
		push(i);
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		printf("%d ", towerReceive[i]);
	}
}

int isEmpty() {
	if (front == 0) {
		return 1;
	}
	return 0;
}
void push(int v) {
	stack[front++] = v;
}

int pop() {
	return stack[--front];
}

int top() {
	return stack[front - 1];
}

void init() {
	scanf("%d", &n);
	list = (int*)malloc(n * sizeof(int));
	stack = (int*)malloc(n * sizeof(int));
	towerReceive = (int*)calloc(n, sizeof(int));
	front = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
}

void finish() {
	free(list);
	free(stack);
}