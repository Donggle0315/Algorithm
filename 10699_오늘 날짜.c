#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

int main() {
	struct tm* t;
	time_t a = time(NULL);

	t = localtime(&a);

	printf("%d-%d-%d\n", t->tm_year+1900, t->tm_mon+1, t->tm_mday);


	return 0;
}