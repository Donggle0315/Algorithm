#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
	int hour, minute, cookhour, cookminute;
	scanf("%d %d", &hour, &minute);
	scanf("%d", &cookminute);
	cookhour = (cookminute / 60)%24;
	cookminute %= 60;
	minute += cookminute;
	if (minute >= 60) {
		hour += minute / 60;
		minute %= 60;
	}
	hour += cookhour;
	if (hour >= 24) {
		hour %= 24;
	}
	printf("%d %d", hour, minute);
}