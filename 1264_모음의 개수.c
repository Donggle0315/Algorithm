#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int i, n;
	char str[256];
	gets(str);
	while (str[0] != '#') {
		n = 0;
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] == 'a' || str[i] == 'A' || str[i] == 'E' || str[i] == 'e' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U') {
				n++;
			}
		}
		printf("%d\n", n);
		gets(str);
	}

	return 0;
}
