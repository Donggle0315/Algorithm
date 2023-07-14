#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void init();
void push(char);
void pop();
int empty();
int size();
int checking();

int n;
char str[2001];
char stack[2000];
int front = 0;
int need = 0;


int main() {
	init();

	return 0;
}

void init() {
	int i,re;
	for (i = 1;; i++) {
		scanf("%s", str);
		if (str[0] == '-') {
			break;
		}
		re = checking();
		printf("%d. %d\n", i, re);
		front = 0;
	}
}

int checking() {
	int i;
	need = 0;//연산의 수
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '{') {//'{'일 경우 push
			push(str[i]);
		}
		else {//'}'일 경우 pop
			pop();
		}
	}
	need += (size() / 2);//남은 '{'의 수. 중 절반을 '}'로 바꾸어 짝을 맞춤
	return need;
}

void push(char n) {
	stack[front++] = n;
}

void pop() {
	if (empty() == 1) {//꺼낼 수가 없다면,
		need++;//'}'을 '{'로 바꿈
		push('{');
	}
	else {
		front--;
	}
}

int empty() {
	if(front==0){
		return 1;
	}
	return 0;
}

int size() {
	return front;
}