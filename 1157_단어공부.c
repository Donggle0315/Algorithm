#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,max=0,flag=1;
	int* alpha = (int*)calloc(26, sizeof(int));
	char* s= (char*)malloc(1000000 * sizeof(char));
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			alpha[s[i] - 'A']++;
		}
		else {
			alpha[s[i] - 'a']++;
		}
	}

	for (i = 1; i < 26; i++) {
		if (alpha[max] == alpha[i]) {
			flag = 0;
		}
		if (alpha[max] < alpha[i]) {
			max = i;
			flag = 1;
		}
	}

	if (flag == 0) {
		printf("?");
	}
	else {
		printf("%c", max + 'A');
	}

	free(alpha);
	free(s);


	return 0;
}