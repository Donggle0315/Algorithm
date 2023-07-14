#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	double num;
	double PI = 3.14159265359;
	scanf("%lf", &num);

	printf("%lf\n%lf", num * num * PI, num * num + num * num);

	return 0;
}