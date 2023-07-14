#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char str[8];
	int num[10] = { 0 };
	int max = 0;
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++) {
		num[str[i] - '0']++;
	}
	num[6] += num[9];
	num[6] = (num[6] + 1) / 2;
	for (int i = 0; i < 9; i++) {
		if (num[i] > max) {
			max = num[i];
		}
	}
	printf("%d", max);

	return 0;
}