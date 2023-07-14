#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	long long s;
	long long n = 0;
	long long i;
	scanf("%lld", &s);
	for (i = 1;n<=s; i++) {
		n += i;
	}
	printf("%lld", i - 2);

	return 0;
}