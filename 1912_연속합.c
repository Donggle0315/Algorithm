#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int init();



int main() {
	printf("%d", init());


	return 0;
}

int init() {
	int max = -1001, n, sum = 0;
	int i,in;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &in);
		sum += in;//������
		if (sum > max) {//�������� �ִ밪�̸�
			max = sum;
		}
		if (sum < 0) {//������ ���´ٸ�
			sum = 0;
		}
	}
	return max;

}