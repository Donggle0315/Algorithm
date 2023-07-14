#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int fibo(int);

int main() {
	int n;
	int a = 0, b = 1;
	int c;
	scanf("%d", &n);
	if (n == 1) {
		c = 1;
	}
	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	printf("%d", c);
}

