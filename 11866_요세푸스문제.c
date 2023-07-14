#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int pop(int*, int*,int);
void add(int*, int*, int, int);

int main() {
	int num,front,rear,n,k,count=0,out=0;
	int* queue;
	scanf("%d %d", &num,&k);
	queue = (int*)calloc(num, sizeof(int));
	for (front=0,rear=0; front < num; front++) {
		queue[front] = front + 1;
	}
	front--;
	printf("<");
	while (out<num) {
		n = pop(queue, &rear,num);
		if (n != 0) {
			count++;
		}
		if (count == k) {
			count = 0;
			out++;
			if (out == num) {
				printf("%d", n);
			}
			else {
				printf("%d, ", n);
			}
			continue;
		}
		add(queue, &front, num, n);
	}
	printf(">");


	free(queue);

	return  0;
}

int pop(int* queue,int* rear,int num) {
	int n = queue[*rear];
	queue[*rear] = 0;
	if (*rear == num-1) {
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