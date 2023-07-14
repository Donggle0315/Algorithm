#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	long long a, b, c;
	
	scanf("%ld %ld %ld", &a, &b, &c);
	a += b;
	a += c;
	printf("%ld", a);


	return 0;
}