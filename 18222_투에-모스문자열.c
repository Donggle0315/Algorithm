#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void init();
int countingpow(long long);

long long num;

int main() {
	init();
	printf("%d", countingpow(num-1));

}

void init() {
	scanf("%lld", &num);
}

int countingpow(long long n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n % 2 == 0) {
		return countingpow(n / 2);
	}
	else if (n % 2 != 0) {
		return 1 - countingpow(n / 2);
	}
}
/*
https://ko.wikipedia.org/wiki/%ED%88%AC%EC%97%90-%EB%AA%A8%EC%8A%A4_%EC%88%98%EC%97%B4
에 나온 점화식을 참고하였음
*/