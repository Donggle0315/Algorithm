#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void finish();
void push(int);
int pop();
int size();
int empty();
int front();
int back();

int* queue;
int head;
int rear;
int num;

int main() {
	char* str = (char*)malloc(6 * sizeof(char));
	int i,n;
	scanf("%d", &num);
	init();

	for (i = 0; i < num; i++) {
		scanf("%s", str);
		if (strcmp(str, "push")==0) {
			scanf("%d", &n);
			push(n);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n",pop());
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(str, "front") == 0) {
			printf("%d\n", front());
		}
		else if (strcmp(str, "back") == 0) {
			printf("%d\n", back());
		}
	}


	finish();
	free(str);

	return 0;
}

void init() {
	queue = (int*)malloc(num * sizeof(int));
	head = 0;
	rear = 0;
}

void finish() {
	free(queue);
}

void push(int n) {
	if (head == num) {
		head = 0;
	}
	queue[head++]=n;
}

int pop() {
	if (rear == num) {
		rear = 0;
	}
	if (rear == head) {
		return -1;
	}
	else {
		return queue[rear++];
	}
}

int size() {
	return head - rear;
}

int empty() {
	if (rear == head) {
		return 1;
	}
	else {
		return 0;
	}
}

int front() {
	if (empty() == 1) {
		return -1;
	}
	if (rear == num) {
		return queue[0];
	}
	return queue[rear];
}

int back() {
	if (empty() == 1) {
		return -1;
	}
	if (head == num) {
		return queue[0];
	}
	return queue[head-1];
}