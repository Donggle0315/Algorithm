#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct element {
	int grade;
	int mark;
}element;

void init();
void finish();
void push(element*);
element* pop();
int size();
void cal();


element* queue;
int head;
int rear;
int n;

int main() {
	int i, re;
	scanf("%d ", &re);
	for (i = 0; i < re; i++) {
		cal();
	}


	return 0;
}


void cal() {
	int max, i, count = 0, s, flag;
	element* a;
	init();
	while (size() != 0) {
		flag = 0;
		max = 0;
		s = size();
		for (i = 0; i < s; i++) {
			a = pop();
			if (a->grade > max) {
				max = a->grade;
			}
			push(a);

		}
		while (flag == 0) {
			a = pop();
			if (a->grade == max) {
				count++;
				if (a->mark == 1) {
					printf("%d\n", count);
					break;
				}
				flag = 1;
			}
			else {
				push(a);

			}
		}
	}
	finish();
}

void init() {
	int m, i, num;
	element* in = (element*)malloc(sizeof(element));
	scanf("%d %d ", &n, &m);
	queue = (element*)malloc(n * sizeof(element));
	head = 0;
	rear = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		in->grade = num;
		in->mark = 0;
		push(in);
	}
	queue[m].mark = 1;
	
}

void finish() {
	free(queue);
}

void push(element* num) {
	if (head == n) {
		head = 0;
	}
	queue[head].mark = num->mark;
	queue[head++].grade = num->grade;

}

element* pop() {
	if (rear == n) {
		rear = 0;
	}

	return &queue[rear++];
}

int size() {
	int size = 0;
	if (head >= rear) {
		return head - rear;
	}
	else {
		return (head - 1) + (n - rear + 1);
	}
}