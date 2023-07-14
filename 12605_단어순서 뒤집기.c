#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void finish();
void push(char*);
void pop();
int empty();

char* str;
char** stack;
int front;
char seps[] = " ";

int main() {
	int i,n;
	char* token;
	scanf("%d ", &n);

	for (i = 0; i < n; i++) {
		init(26);
		gets_s(str, 26);
		token = strtok(str, seps);
		while (token != NULL) {
			push(token);
			token = strtok(NULL, seps);
		}
		printf("Case #%d: ", i + 1);
		while (empty() == 0) {
			pop();
		}
		printf("\n");
		finish();
	}

	return 0;
}

void init() {
	int i;
	stack = (char**)malloc(13 * sizeof(char*));
	for (i = 0; i < 13; i++) {
		stack[i] = (char*)malloc(26 * sizeof(char));
	}
	front = 0;
	str = (char*)malloc(26 * sizeof(char));
}

void finish() {
	int i;
	for (i = 0; i < 13; i++) {
		free(stack[i]);
	}
	free(stack);
	free(str);
}

void push(char* n) {
	int i;
	for (i = 0; n[i] != '\0'; i++) {
		stack[front][i] = n[i];
	}
	stack[front++][i] = '\0';
}

void pop() {
	int i;
	if (front == 0) {
		return ;
	}
	front--;
	for (i = 0; stack[front][i] != '\0'; i++) {
		printf("%c", stack[front][i]);
	}
	printf(" ");
}

int empty() {
	if (front == 0) {
		return 1;
	}
	return 0;
}