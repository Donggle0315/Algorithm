#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init(int);
void finish();
void push(int);
int pop();
int empty();

int* stack;
int front;
int *list;
int* tmp;
int s;



int main() {
	int i,n,num,max=0;
	scanf("%d", &num);

	init(num);

	for (i = 0; i < num; i++) {
		scanf("%d", &list[i]);
	}

	for (i = num-1; i >=0; i--) {
		if (empty()==1) {
			tmp[i] = -1;
			push(list[i]);
		}
		else {
			do {
				s = pop();
				if (s > list[i]) {
					tmp[i] = s;
					push(s);
					push(list[i]);
				}
			} while (s <= list[i] && empty() == 0);
			if (tmp[i] == 0) {
				tmp[i] = -1;
				push(list[i]);
			}
		}
	}

	for (i = 0; i < num; i++) {
		printf("%d ", tmp[i]);
	}



	finish();

	return 0;
}

void init(int n) {
	stack = (int*)malloc(n * sizeof(int));
	list = (int*)malloc(n * sizeof(int));
	tmp = (int*)calloc(n,sizeof(int));
	s = 0;
	front = 0;
}

void finish() {
	free(stack);
	free(list);
	free(tmp);
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