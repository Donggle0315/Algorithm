#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	char* s = (char*)malloc(1000000 * sizeof(char));
	int i,count = 0;
	gets(s);
	for (i = 0; s[i] != '\0'; i++) {
		if (i == 0&&s[i]!=' ') {
			count++;
		}
		if (s[i] == ' '&&s[i+1]!='\0') {
			count++;
		}
	}

	printf("%d", count);


	free(s);

	return 0;
}