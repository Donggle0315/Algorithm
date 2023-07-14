#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
long long findMax();


long long n, m;
long long* tree;
long long max = 0;


int main() {
	init();
	printf("%lld", findMax());
	finish();
	

	return 0;
}


long long findMax() {
	long long left = 0;
	long long right=max;
	long long mid;
	long long sum;
	long long result=0;
	long long i;
	while (left <= right) {
		mid = (long long)(left + right) / 2;
		sum = 0;
		for (i = 0; i < n; i++) {
			if (tree[i] > mid) {
				sum += (tree[i] - mid);
			}
		}
		if (sum >= m) {
			if (result < mid) {
				result = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	
	return result;
}

void init() {
	int i;
	
	scanf("%lld %lld", &n, &m);
	tree = (long long*)malloc(n * sizeof(long long));
	for (i = 0; i < n; i++) {
		scanf("%lld", &tree[i]);
		if (tree[i] > max) {
			max = tree[i];
		}
	}
}

void finish() {
	free(tree);
}