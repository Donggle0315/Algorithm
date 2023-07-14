#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void div2();
void deleteLast1();
int cal();

long long a, b;
int count = 0;

int main() {
	scanf("%lld %lld", &a, &b);
	printf("%d", cal());
	return 0;
}

int cal() {
	if (a == b) {
		return count+1;
	}
	if (a > b||(b%10>1&&b%2==1)) {
		return -1;
	}
	if (b % 10 == 1) {
		deleteLast1();
	}
	else if (b % 2 == 0) {
		div2();
	}
	return cal();
}

void deleteLast1() {
	b /= 10;
	count++;
}

void div2() {
	b /= 2;
	count++;
}