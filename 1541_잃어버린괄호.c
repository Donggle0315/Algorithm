#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void findMin();
int isEmpty();
int pop();

char str[51];
int list[51];//-1이 빼기 -2는 더하기
int count = 0;
int front = 0;

int main() {
	init();
	findMin();

	return 0;
}

void init() {
	scanf("%s", str);
	int k=0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '+') {
			list[count++] = k;
			k = 0;
			list[count++] = -2;
		}
		else if (str[i] == '-') {
			list[count++] = k;
			k = 0;
			list[count++] = -1;
		}
		else {
			k *= 10;
			k += (str[i] - '0');
		}
	}
	list[count++] = k;

}

void findMin() {
	int sum = 0;
	int tmp = 0;
	int flag = 0;
	while (isEmpty() == 0) {
		int k = pop();
		if (flag == 0 && k == -1) {
			flag = 1;
		}
		else if (flag == 0 && k != -2 && k != -1) {
			sum += k;
		}
		else if (flag == 1 && k == -1) {
			sum -= tmp;
			tmp = 0;
		}
		else if (flag == 1 && k != -2) {
			tmp += k;
		}
	}
	sum -= tmp;
	printf("%d", sum);
}

int isEmpty() {
	if (front == count) {
		return 1;
	}
	return 0;
}

int pop() {
	return list[front++];
}