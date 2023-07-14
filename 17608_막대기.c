#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(int);
void finish();
void push(int);
int pop();
int empty();

int* stack;
int front;

int main() {
	int num, i, n,m,count=1;

	scanf("%d", &num);
	init(num);
	for (i = 0; i < num; i++) {
		scanf("%d", &n);
		push(n);
	}

	n = pop();
	while (empty() != 1) {
		m = pop();
		if (n >= m) {
			continue;
		}
		else {
			n = m;
			count++;
		}
	}

	printf("%d", count);
	finish();

	return 0;
}

void init(int n) {
	stack = (int*)malloc(n * sizeof(int));
	front = 0;
}

void finish() {
	free(stack);
}

void push(int n) {
	stack[front++] = n;
}

int pop() {
	if (front == 0) {
		return -1;
	}
	return stack[--front];
}

int empty() {
	if (front == 0) {
		return 1;
	}
	return 0;
}