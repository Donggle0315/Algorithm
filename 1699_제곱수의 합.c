#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void init();
void findValue();

int num;
int list[100001];


int main() {
	init();
	findValue();
	printf("%d", list[num]);

	return 0;
}

void init() {
	scanf("%d", &num);
	list[0] = 0;
	list[1] = 1;
	list[2] = 2;
	list[3] = 3;
}


void findValue() {
	int i,j;
	for (i = 4; i <= num; i++) {
		list[i] = list[i - 1] + 1;//i-1번쨰 수 + 1^2
		for (j = 1; j * j <= i; j++) {//더 작게 만들 수 있는지 조사
			if (list[i - j * j]+1 < list[i]) {
				list[i] = list[i - j * j] + 1;
			}
		}
	}
}