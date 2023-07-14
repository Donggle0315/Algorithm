#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int money;
	int change = 0;
	scanf("%d", &money);
	money = 1000 - money;
	change += money / 500;
	money %= 500;
	change += money / 100;
	money %= 100;
	change += money / 50;
	money %= 50;
	change += money / 10;
	money %= 10;
	change += money / 5;
	money %= 5;
	change += money;
	printf("%d", change);
	return 0;
}