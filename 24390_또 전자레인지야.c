#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void countClick();

int second;

int main() {
	init();
	countClick();

	return 0;
}

void countClick() {
	//10s, 30s, 60s, 600s
	//시간을 맞추고 조리 누르기
	//조리 누르고 시간 맞추고 
	int flag = 0;
	int count = 0;
	count += second / 600;
	second %= 600;
	count += second / 60;
	second %= 60;
	if (second >= 30) {
		flag = 1;
	}
	count += second / 30;
	second %= 30;
	count += second / 10;
	second %= 10;
	if (flag == 0) {
		count++;
	}

	printf("%d", count);
}

void init() {
	char str[6];
	scanf("%s", str);
	second = (str[0] - '0') * 600 + (str[1] - '0') * 60 + (str[3] - '0') * 10 + (str[4] - '0');
}