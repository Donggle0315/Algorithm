#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
1. 사는 경우 : 뒤에 더 높은 날이 있을 때
2. 파는 경우 : 뒤에 더 높은 날이 없을 때
3. 아무것도 안하는 경우 : 주식이 없는데 뒤에 낮은 날만 있을 때
*/

void init();
long long findMax();

int n;
int list[1000000];

int main() {
	int i;
	init();
	for (i = 0; i < n; i++) {
		printf("%lld\n", findMax());
	}

	return 0;
}

void init() {
	scanf("%d", &n);
}

long long findMax() {
	int num, i;
	int max = 0;
	long long money = 0;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &list[i]);
	}
	max = list[num - 1];
	for (i = num - 1; i >= 0; i--) {
		if (list[i] < max) {
			money += max - list[i];
		}
		else {
			max = list[i];
		}
	}
	
	return money;

}