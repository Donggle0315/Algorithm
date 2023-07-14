#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,i,j,k;
	int* r;
	char** s;
	scanf("%d", &num);
	r = (int*)malloc(sizeof(int) * num);
	s = (char**)malloc(sizeof(char*) * num);
	for (i = 0; i < num; i++) {
		s[i] = (char*)malloc(sizeof(char) * 20);
	}

	for (i = 0; i < num; i++) {
		scanf("%d %s", &r[i], s[i]);
	}

	for (i = 0; i < num; i++) {
		for (j = 0; s[i][j] != '\0'; j++) {
			for (k = 0; k < r[i]; k++) {
				printf("%c", s[i][j]);
			}
		}
		printf("\n");
	}

	for (i = 0; i < num; i++) {
		free(s[i]);
	}
	free(s);
	free(r);


	return 0;
}