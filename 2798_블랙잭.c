#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int a, b, i, j, k,sum,max=0;
	int* list;
	scanf("%d %d", &a,&b);
	list = (int*)malloc(a * sizeof(int));
	for (i = 0; i < a; i++) {
		scanf("%d", &list[i]);
	}
	for (i = 0; i < a-2; i++) {
		sum = 0;
		if (sum+list[i] > b) {
			continue;
		}
		sum += list[i];

		for (j = i + 1; j < a - 1; j++) {
			if (sum+list[j] > b) {
				continue;
			}
			sum += list[j];

			for (k = j + 1; k < a; k++) {
				if (sum+list[k] > b) {
					continue;
				}
				sum += list[k];

				if (sum > max) {
					max = sum;
				}

				sum -= list[k];
			}
			sum -= list[j];
		}
		sum -= list[i];
	}
	printf("%d\n", max);



	free(list);

	return 0;
}