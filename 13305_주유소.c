#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
long long findMinValue();

int n;
int* distance;
int* city;

int main() {
	init();
	printf("%lld", findMinValue());
	finish();

	return 0;
}

long long findMinValue() {
	long long sum = 0;
	long long minCity=city[0];
	long long sumDistance=distance[0];
	for (int i = 1; i < n-1; i++) {
		if (city[i] < minCity) {
			sum += sumDistance * minCity;
			minCity = city[i];
			sumDistance = distance[i];
		}
		else {
			sumDistance += distance[i];
		}
	}
	sum += minCity * sumDistance;

	return sum;
}

void init() {
	scanf("%d", &n);
	distance = (int*)malloc(n * sizeof(int));
	city = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &distance[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &city[i]);
	}
}

void finish() {
	free(distance);
	free(city);
}