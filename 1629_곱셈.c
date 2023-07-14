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
	if (i == 1) {//1번 곱하는 경우
		return a % c;
	}
	else if (i % 2 == 1) {//홀수번 곱해야 하는 경우
		return ((multiply(i / 2) * multiply(i / 2))%c * a)%c;
	}
	else {//짝수번 곱해야 하는 경우
		return (multiply(i / 2) * multiply(i / 2)) % c;
	}
}