#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
int checking();
void push(int);
void pop();
int last();
int empty();


int n;
int* stack;
int* input;
char* output;
int opp = 0;
int sp = 0;

int main() {
	int i,result;
	init();
	result=checking();
	if (result == -1) {
		printf("NO\n");
	}
	else {
		for (i = 0; i < opp; i++) {
			printf("%c\n", output[i]);
		}
	}
	finish();
	return 0;
}

int checking() {
	int i,cnt=0;
	for (i = 1; i <= n; i++) {
		push(i);
		while (empty() == 1 && last() == input[cnt]) {
			pop();
			cnt++;
		}
	}

	if (empty() == 1) {
		return -1;
	}
	else {
		return 1;
	}
}

void push(int a){
	stack[sp++] = a;
	output[opp++] = '+';
}

void pop() {
	sp--;
	output[opp++] = '-';
}

int last() {
	return stack[sp - 1];
}

int empty() {
	if (sp == 0) {
		return 0;
	}
	return 1;
}


void init() {
	int i;
	scanf("%d", &n);
	stack = (int*)malloc(n * sizeof(int));
	input = (int*)malloc(n * sizeof(int));
	output = (char*)malloc(3 * n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
}

void finish() {
	free(stack);
	free(input);
	free(output);
}