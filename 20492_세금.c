#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int money;
	scanf("%d", &money);
	printf("%d\n", money - (money / 100 * 22));
	printf("%d", money - (money / 100 * 20 / 100 * 22));


	return 0;
}