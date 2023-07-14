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
			//n/h가 나머지를 남기므로, 옆방으로 한칸 이동
		}
		a = n % h;
		if (n % h == 0) {
			a = h;
			//가장 꼭대기 층에 있는 방
		}
		printf("%d%02d\n", a, b);
		
	}

	return 0;
}