#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void printResult();
void push(int);
void deleteq();
int isEmpty();
void reverse();
void printing();


int deque[100000];
int front, rear;
int direction;//0이면 start가 앞, 1이면 rear가 앞


char function[400001];
int n;
char str[400001];


int main() {
	int tc,i;
	scanf("%d", &tc);
	for (i = 0; i < tc; i++) {
		init();
		printResult();
	}

	return 0;
}


void init() {
	int i;
	int tmp=0;
	scanf("%s", function);
	scanf("%d", &n);
	scanf("%s", str);

	front = -1;
	rear = 0;
	direction = 0;
	for (i = 0; str[i] != 0; i++) {
		if (str[i] <= '9' && str[i] >= '0') {
			tmp *= 10;
			tmp += str[i] - '0';
		}
		else {
			if (tmp != 0) {
				push(tmp);
			}
			tmp = 0;
		}
	}
}


void push(int k) {
	deque[rear++]=k;
}

void printResult() {
	int i;
	for (i = 0; function[i] != 0; i++) {
		if (function[i] == 'R') {
			reverse();
		}
		else {
			if (isEmpty() == 1) {
				printf("error\n");
				return;
			}
			else {
				deleteq();
			}
		}
	}
	printing();
}


void reverse() {
	if (direction == 0) {
		direction = 1;
	}
	else {
		direction = 0;
	}
}

int isEmpty() {
	if (rear == front + 1) {
		return 1;
	}
	return 0;
}

void deleteq() {
	if (direction == 0) {
		front++;
	}
	else {
		rear--;
	}
}

void printing() {
	int i;
	printf("[");
	if (direction == 0) {
		for (i = front + 1; i < rear; i++) {
			printf("%d", deque[i]);
			if (i != rear - 1) {
				printf(",");
			}
		}
	}
	else {
		for (i = rear - 1; i > front; i--) {
			printf("%d", deque[i]);
			if (i != front + 1) {
				printf(",");
			}
		}
	}
	printf("]\n");
}