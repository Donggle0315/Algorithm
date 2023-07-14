#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(int);
void finish();
void push(char,int);
char pop(int);
int empty();

char* stack1;
char* stack2;
char* str;
int front1,front2;

int main() {
	int i, small,big,flag;
	char c;

	while (1) {
		init(101);
		small = 0; 
		big = 0;
		flag = 0;
		gets_s(str, 101);
		if (str[0] == '.' && str[1] == '\0') {
			break;
		}
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] == '(' || str[i] == '['||str[i]==')'||str[i]==']') {
				push(str[i],1);
			}
		}

		while (empty() != 1) {
			c = pop(1);
			if (c == ']') {
				big++;
				push(c, 2);
			}
			else if (c == '[') {
				if (big == 0||pop(2)!=']') {
					flag = 1;
					break;
				}
				else {
					big--;
				}
			}
			else if (c == ')') {
				small++;
				push(c, 2);
			}
			else if (c == '(') {
				if (small == 0||pop(2)!=')') {
					flag = 1;
					break;
				}
				else {
					small--;
				}
			}
		}
		if (flag == 0 &&small==0 && big==0) {
			printf("yes\n");
		}
		else {
			printf("no\n");
			flag = 0;
		}
		finish();
	}
	return 0;
}

void init(int n) {
	stack1 = (char*)malloc(n * sizeof(char));
	stack2 = (char*)malloc(n * sizeof(char));
	str = (char*)malloc(n * sizeof(char));
	front1 = 0;
	front2 = 0;
}

void finish() {
	free(stack1);
	free(stack2);
	free(str);
}

void push(char n, int k) {
	if (k == 1) {
		stack1[front1++] = n;
	}
	else {
		stack2[front2++] = n;
	}
}

char pop(int n) {
	if (n == 1) {
		if (front1 == 0) {
			return -1;
		}
		return stack1[--front1];
	}
	else {
		if (front2 == 0) {
			return -1;
		}
		return stack2[--front2];
	}
	
}

int empty() {
	if (front1 == 0) {
		return 1;
	}
	return 0;
}