#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int x, y,re=0;
	scanf("%d %d", &x, &y);
	printf("%d\n", x * (y % 10));
	re += x * (y % 10);
	y /= 10;

	printf("%d\n", x * (y % 10));
	re += x * (y % 10)*10;
	y /= 10;

	printf("%d\n", x * (y % 10));
	re += x * (y % 10)*100;
	y /= 10;
	printf("%d", re);
	return 0;
}