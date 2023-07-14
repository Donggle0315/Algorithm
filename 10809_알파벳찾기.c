#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	const int ALPHA = 26;
	int* alphabet = (int*)malloc(sizeof(int) * ALPHA);
	char* s = (char*)malloc(sizeof(char) * 100);
	int i;

	for (i = 0; i < ALPHA; i++) {
		alphabet[i] = -1;
	}
	
	scanf("%s", s);

	for (i = 0; s[i] != '\0'; i++) {
		if (alphabet[s[i] - 'a'] != -1) {
			continue;
		}
		alphabet[s[i] - 'a'] = i;
	}

	for (i = 0; i < ALPHA; i++) {
		printf("%d ", alphabet[i]);
	}

	free(alphabet);
	free(s);

	return 0;
}