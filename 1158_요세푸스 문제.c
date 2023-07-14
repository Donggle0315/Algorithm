#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, k;
	int* list;
	scanf("%d %d", &n, &k);
	list = (int*)calloc(n, sizeof(int));

	int idx = -1;
	int count = 0;
	printf("<");
	while (count != n) {
		for (int i = 0; i < k; i++) {
			idx=(idx+1)%n;
			while (list[idx] != 0) {
				idx = (idx + 1) % n;
			}
		}
		list[idx] = 1;
		count++;
		if (count == n) {
			printf("%d", idx + 1);
		}
		else {
			printf("%d, ", idx + 1);

		}
		
	}
	printf(">");

	free(list);

	return 0;
}