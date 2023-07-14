#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void finish();
void push_front(int);
void push_back(int);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();

int* deque;
int head, rear, num;

int main() {
	int i,n;
	char* str = (char*)malloc(11 * sizeof(char));
	scanf("%d", &num);
	init();
	for (i = 0; i < num; i++) {
		scanf("%s", str);
		if (strcmp(str, "push_front") == 0) {
			scanf("%d", &n);
			push_front(n);
		}
		else if (strcmp(str, "push_back") == 0) {
			scanf("%d", &n);
			push_back(n);
		}
		else if (strcmp(str, "pop_front") == 0) {
			printf("%d\n",pop_front());
		}
		else if (strcmp(str, "pop_back") == 0) {
			printf("%d\n", pop_back());
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
	deque = (int*)malloc(num * sizeof(int));
	head = num/2+1;
	rear = num/2;
}

void finish() {
	free(deque);
}

void push_front(int n) {
	if (head == num) {
		head = 0;
	}
	deque[head++] = n;
}

void push_back(int n) {
	if (rear == -1) {
		rear = num - 1;
	}
	deque[rear--] = n;
}

int pop_front() {
	if (head == 0) {
		head = num;
	}
	if (empty() == 1) {
		return -1;
	}
	return deque[--head];
}

int pop_back() {
	if (rear == num - 1) {
		rear = -1;
	}
	if (empty()==1) {
		return -1;
	}
	return deque[++rear];
}

int size() {
	int i,count = 0;
	if (rear <= head) {
		for (i = rear + 1; i < head; i++, count++) {
			;
		}
	}
	else {
		for (i = 0; i < head; i++, count++) {
			;
		}
		for (i = rear + 1; i < num; i++, count++) {
			;
		}
	}
	return count;
}

int empty() {
	if (head-1 == rear) {
		return 1;
	}
	return 0;
}

int front() {
	if (empty() == 1) {
		return -1;
	}
	if (head == 0) {
		return deque[num - 1];
	}
	return deque[head - 1];
}

int back() {
	if (empty() == 1) {
		return -1;
	}
	if (rear == num - 1) {
		return deque[0];
	}
	return deque[rear + 1];
}