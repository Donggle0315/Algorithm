#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num,i,h,w,n,a,b;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d %d", &h, &w, &n);
		b = n / h;
		if (n % h != 0) {
			b++;
			//n/h�� �������� ����Ƿ�, �������� ��ĭ �̵�
		}
		a = n % h;
		if (n % h == 0) {
			a = h;
			//���� ����� ���� �ִ� ��
		}
		printf("%d%02d\n", a, b);
		
	}

	return 0;
}