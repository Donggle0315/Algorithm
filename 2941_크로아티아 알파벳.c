#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,count = 0;
	char* s = (char*)malloc(100 * sizeof(char));
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == 'c') {
			if (s[i + 1] == '=' || s[i + 1] == '-') {
				i++;
			}
		}
		if (s[i] == 'd') {
			if (s[i + 1] == 'z' && s[i + 2] == '=') {
				i += 2;
			}
			if (s[i + 1] == '-') {
				i++;
			}
		}
		if (s[i] == 'l'||s[i]=='n') {
			if (s[i + 1] == 'j') {
				i++;
			}
		}
		if (s[i] == 's' || s[i] == 'z') {
			if (s[i + 1] == '=') {
				i++;
			}
		}
		count++;
	}
	printf("%d", count);

	free(s);

	return 0;
}