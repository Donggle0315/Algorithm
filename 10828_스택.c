#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(int);
void finish();
void push(int);
int pop();
int size();
int empty();
int top();

int* stack;
int front;

int main() {
	int num,i,n;
	char* input=(char*)malloc(15*sizeof(char));
	
	scanf("%d", &num);
	init(num);
	for (i = 0; i < num; i++) {
		scanf("%s", input);
		if (strcmp(input, "push")==0) {
			scanf("%d", &n);
			push(n);
		}
		else if (strcmp(input, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(input, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(input, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(input, "top") == 0) {
			printf("%d\n", top());
		}
	}

	finish();
	free(input);

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

int size() {
	return front;
}

int empty() {
	if (front == 0) {
		return 1;
	}
	return 0;
}

int top() {
	if (front == 0) {
		return -1;
	}
	return stack[front - 1];
}