#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long multiply(long long);
void init();

long long a, b, c;

int main() {
	init();
	printf("%lld", multiply(b));


	return 0;
}

void init() {
	scanf("%lld %lld %lld", &a, &b, &c);
}

long long multiply(long long i) {
	if (i == 1) {//1�� ���ϴ� ���
		return a % c;
	}
	else if (i % 2 == 1) {//Ȧ���� ���ؾ� �ϴ� ���
		return ((multiply(i / 2) * multiply(i / 2))%c * a)%c;
	}
	else {//¦���� ���ؾ� �ϴ� ���
		return (multiply(i / 2) * multiply(i / 2)) % c;
	}
}