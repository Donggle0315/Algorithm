#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int time;
	scanf("%d", &time);
	if (time % 10 != 0) {
		printf("-1");
	}
	else {
		printf("%d ", time / 300);
		time %= 300;
		printf("%d ", time / 60);
		time %= 60;
		printf("%d", time / 10);
	}
	return 0;

}