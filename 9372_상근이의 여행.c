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
		printf("%d\n", n - 1);//�ּҽ���Ʈ���� ���� ���� ������ ����� ����̹Ƿ�, �ּҽ���Ʈ���� ������ ���� n-1�� ���
	}


	return 0;
}