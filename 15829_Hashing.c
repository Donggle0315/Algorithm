#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	char* str;
	int i, num;
	long long sum = 0, mod = 1234567891, r = 1;
;
	scanf("%d", &num);
	str = (char*)malloc((num + 1) * sizeof(char));
	scanf("%s", str);
	for (i = 0; i < num; i++) {
		sum += (str[i] - 'a' + 1) * r;
		sum %= mod;
		r*=31;
		r %= mod;
	}
	printf("%lld", sum);

	free(str);

	return 0;
}