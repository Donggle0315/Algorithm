#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int pop(int*, int*, int);
void add(int*, int*, int, int);

int main() {
	int num, front, rear, n, out = 0;
	int* queue;
	scanf("%d", &num);
	queue = (int*)calloc(num, sizeof(int));
	for (front = 0, rear = 0; front < num; front++) {
		queue[front] = front + 1;
	}
	front--;
	while (out < num-1) {
		n = pop(queue, &rear, num);
		out++;
		n = pop(queue, &rear, num);
		add(queue, &front, num, n);
	}
	printf("%d", pop(queue, &rear, num));

	free(queue);

	return  0;
}

int pop(int* queue, int* rear, int num) {
	int n = queue[*rear];
	queue[*rear] = 0;
	if (*rear == num - 1) {
		*rear = 0;
	}
	else {
		(*rear)++;
	}
	return n;
}

void add(int* queue, int* front, int num, int n) {
	if (*front == num - 1) {
		*front = 0;
	}
	else {
		(*front)++;
	}
	queue[*front] = n;

}