#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int cycle, n, m;
	int i,j,a,b;
	scanf("%d", &cycle);
	for (i = 0; i < cycle; i++) {
		scanf("%d %d", &n, &m);
		for (j = 0; j < m; j++) {
			scanf("%d %d", &a, &b);
		}
		printf("%d\n", n - 1);//최소신장트리가 가장 적은 종류의 비행기 경로이므로, 최소신장트리의 간선의 개수 n-1을 출력
	}


	return 0;
}