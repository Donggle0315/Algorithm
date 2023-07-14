#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int kg,i,j,flag=0,sum;
	scanf("%d", &kg);
	for (i = kg/5;i>=0; i--) {
		for (j = (kg-5*i)/3;j>=0; j--) {
			if (kg-i*5-j*3 == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	if (i == -1 && j == -1) {
		sum = -1;
	}
	else {
		sum = i + j;
	}
	printf("%d", sum);



	return 0;
}