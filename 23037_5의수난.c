#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


int main() {
	int num, sum=0;

	scanf("%d", &num);

	while (num != 0) {
		sum += pow(num % 10, 5);
		num /= 10;
	}
	printf("%d", sum);

	return 0;
}