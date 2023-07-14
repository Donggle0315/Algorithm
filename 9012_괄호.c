#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,i,j,a,b;
	char* str;


	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		str = (char*)malloc(51 * sizeof(char));
		scanf("%s", str);
		a = 0;
		for (j = 0; j < strlen(str); j++) {
			if (str[j] == '(') {
				a++;
			}
			else if (str[j] == ')') {
				if (a == 0) {
					b=1;
				}
				else {
					a--;
				}
			}
		}
		if (a != 0) {
			b = 1;
		}
		if (b == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
			b = 0;
		}
		free(str);
	}

	return 0;
}