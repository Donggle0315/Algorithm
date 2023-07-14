#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void push(int);
int pop();
int size();
int empty();
int front();
int back();
int f = 0;
int r = 0;

int queue[2000000];

int main() {
	int num,k;
	char str[6];
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			scanf("%d", &k);
			push(k);
		}
		else if (strcmp(str, "pop")==0) {
			printf("%d\n", pop());
		}
		else if (strcmp(str, "size")==0) {
			printf("%d\n", size());
		}
		else if (strcmp(str, "empty")==0) {
			printf("%d\n", empty());
		}
		else if (strcmp(str, "front")==0) {
			printf("%d\n", front());
		}
		else if (strcmp(str, "back")==0) {
			printf("%d\n", back());
		}

	}

	return 0;
}

void push(int n) {
	queue[f++] = n;
}
int pop() {
	if (empty() == 1) {
		return -1;
	}
	return queue[r++];
}
int size() {
	return f - r;
}
int empty() {
	if (size() == 0) {
		return 1;
	}
	return 0;
}
int front() {
	if (empty() == 1) {
		return -1;
	}
	return queue[r];
}
int back() {
	if (empty() == 1) {
		return -1;
	}
	return queue[f-1];
}