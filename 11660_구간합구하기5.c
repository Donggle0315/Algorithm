#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int** list;
int n,num;

void init();
int cal();
void finish();

int main() {
	int i;
	init();
	for (i = 0; i < num; i++) {
		printf("%d\n", cal());
	}
	finish();
	return 0;
}

int cal() {
	int x1, x2, y1, y2;
	int a, b, c, re;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	x2 -= 1;
	x1 -= 1;
	y2 -= 1;
	y1 -= 1;
	re = list[x2][y2];
	if (y1 == 0) {
		a = 0;
		c = 0;
		if (x1 == 0) {
			b = 0;
		}
		else {
			b = list[x1 - 1][y2];
		}
	}
	else {
		a = list[x2][y1 - 1];
		if (x1 == 0) {
			b = 0;
			c = 0;
		}
		else {
			b = list[x1 - 1][y2];
			c = list[x1 - 1][y1 - 1];
		}
	}
	re = re - a - b + c;
	return re;
}

void init() {
	int i,j,m,a,b,c;
	scanf("%d %d", &n, &num);
	list = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		list[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			scanf("%d",&m);
			if (i == 0) {
				a = 0;
				b = 0;
				if (j == 0) {
					c = 0;
				}
				else {
					c = list[i][j - 1];
				}
			}
			else {
				if (j == 0) {
					a = 0;
					c = 0;
				}
				else {
					a = list[i - 1][j - 1];
					c = list[i][j - 1];
				}
				b = list[i - 1][j];

			}
			list[i][j] = b + c + m-a;			
		}
	}
}

void finish() {
	int i;
	for (i = 0; i < n; i++) {
		free(list[i]);
	}
	free(list);
}