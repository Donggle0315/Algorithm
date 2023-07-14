#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int fibo0(int);
int fibo1(int);

int main() {
	int num,n, i;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &n);
		printf("%d %d\n", fibo0(n), fibo1(n));
	}

	return 0;
}

int fibo0(int n) {
	int a = 1, b = 0,c,i;
	if (n == 0) {
		return a;
	}
	if (n == 1) {
		return b;
	}
	for (i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int fibo1(int n) {
	int a = 0, b = 1, c,i;
	if (n == 0) {
		return a;
	}
	if (n == 1) {
		return b;
	}
	for (i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}