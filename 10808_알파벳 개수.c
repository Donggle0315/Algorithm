#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char str[101];
	int alpha[26] = { 0 };
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++) {
		alpha[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alpha[i]);
	}

	return 0;
}