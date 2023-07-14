#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char ch;
	while (scanf("%c",&ch)!=-1) {
		printf("%c", ch);
	}
	return 0;
}