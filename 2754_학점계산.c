#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	int i;
	double score;
	char* str = (char*)malloc(3 * sizeof(char));
	scanf("%s", str);
	
	if (str[0] == 'A') {
		score = 4;
	}
	else if (str[0] == 'B') {
		score = 3;
	}
	else if (str[0] == 'C') {
		score = 2;
	}
	else if (str[0] == 'D') {
		score = 1;
	}
	else {
		score = 0;
	}
	if (str[1] == '+') {
		score += 0.3;
	}
	else if (str[1] == '-') {
		score -= 0.3;
	}

	printf("%.1lf", score);

	free(str);

	return 0;
}