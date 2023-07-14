#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	for (int i = 0; i < 3; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int k = 0;
		if (a == 0) {
			k++;
		}
		if (b == 0) {
			k++;
		}
		if (c == 0) {
			k++;
		}
		if (d == 0) {
			k++;
		}
		if (k == 0) {
			printf("%c\n", 'E');
		}
		if (k == 1) {
			printf("%c\n", 'A');
		}
		if (k == 2) {
			printf("%c\n", 'B');
		}
		if (k == 3) {
			printf("%c\n", 'C');
		}
		if (k == 4) {
			printf("%c\n", 'D');
		}
	}
	return 0;
}