#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
int findUseCoin();

int n, k;
int coin[100] = { 0 };
int value[100001] = { 0 };


int main() {
	init();
	printf("%d", findUseCoin());
	
	return 0;
}

void init() {
	int i;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	value[0] = 1;//0원을 만드는 경우의 수 1가지
}

int findUseCoin() {
	int i,j;
	for (i = 0; i < n; i++) {//모든 동전에 대해서
		for (j = coin[i]; j <= k; j++) {//동전으로 만들수 있는 경우의 수
			value[j] += value[j - coin[i]];//이전 동전으로만 만드는 경우의 수 + 현재 동전을 더해서 만드는 경우의 수
		}
	}

	return value[k];
}