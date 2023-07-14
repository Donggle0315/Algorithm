#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	int a,b,c,tmp;

	while (1) {
		scanf("%d %d %d",&a,&b,&c);
		if (a== 0&&b==0&&c==0) {
			break;
		}
		if (b > a && b > c) {
			tmp = b;
			b = a;
			a = tmp;
		}
		if (c > a && c > b) {
			tmp = c;
			c = a;
			a = tmp;
		}
		if (((int)pow(a, 2) == (int)pow(b, 2) + (int)pow(c,2))) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}



	return 0;
}