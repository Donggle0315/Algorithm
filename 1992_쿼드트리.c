#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
void cal(int,int,int);
int calBig(int,int,int);
int n;
int** list;


int main() {
	init();
	if (calBig(0, 0, n)==1) {
		cal(0, 0, n / 2);
	}
	finish();


	return 0;
}


int calBig(int n, int m, int depth) {
	int i, j, a;
	a = list[n][m];
	for (i = 0; i < depth; i++) {
		for (j = 0; j < depth; j++) {
			if (list[i][j] != a) {
				return 1;
			}
		}
	}
	if (a == 1) {
		printf("%d",1);
	}
	else {
		printf("%d",0);
	}
	return 0;
}

void cal(int i, int j, int depth) {
	int a,p,q,m,n;
	int flag;
	if (depth == 0) {
		if (list[0][0] == 0) {
			printf("(0)");
		}
		else {
			printf("(1)");
		}
		return;
	}
	printf("(");
	for (p = 0; p < 2; p++) {
		for (q = 0; q < 2; q++) {
			flag = 0;
			a = list[i + p * depth][j + q * depth];
			for (n = 0; n < depth; n++) {
				for (m = 0; m < depth; m++) {
					if (list[i + p * depth + n][j + q * depth + m] != a) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					break;
				}
			}
			if (flag == 1&&depth!=1) {
				cal(i + p * depth, j + q * depth, depth / 2);
			}
			else if(flag==0){
				printf("%d", a);
			}
		}
	}
	printf(")");
}

void init() {
	int i, j;
	char* str;
	scanf("%d ", &n);
	list = (int**)malloc(n * sizeof(int*));
	str = (char*)malloc(n+1 * sizeof(char));

	for (i = 0; i < n; i++) {
		list[i] = (int*)malloc(n * sizeof(int));
		scanf("%s", str);
		for (j = 0; j < n; j++) {
			list[i][j] = str[j] - '0';
		}
	}
	free(str);
}

void finish() {
	int i;
	for (i = 0; i < n; i++) {
		free(list[i]);
	}
	free(list);
}
