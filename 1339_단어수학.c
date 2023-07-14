#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void setNum();
void finish();
void sort(int, int);

int* num;
int n;

/*
각 자리수의 합을 구한다 자릿수 마다 10,100,1000 단위로
내림차순으로 정렬하여 9부터 부여
합 구하기
*/

int main() {
	init();
	sort(0,25);
	setNum();
	finish();

	return 0;
}

void init() {
	int i,j,pow;
	char* str = (char*)malloc(15 * sizeof(char));
	scanf("%d", &n);
	num = (int*)calloc(26, sizeof(int));

	for (i = 0; i < n; i++) {
		pow = 1;//자릿수
		scanf("%s", str);//문장 하나 입력
		for (j = strlen(str)-1; j>=0; j--) {//낮은 자릿수부터
			if (str[j] >= 'A' && str[j] <= 'Z') {//알파벳이라면
				num[str[j] - 'A'] += pow;//해당 자릿수 만큼 가중치
				pow *= 10;//다음 자릿수
			}
		}
	}
	free(str);
}

void sort(int left, int right) {//가중치를 오름차순으로 정렬
	int pl = left;
	int pr = right;
	int x = num[(left + right) / 2];
	int tmp;
	do {
		while (num[pl] < x) {
			pl++;
		}
		while (num[pr] > x) {
			pr--;
		}
		if (pl <= pr) {
			tmp = num[pl];
			num[pl] = num[pr];
			num[pr] = tmp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (pl < right) {
		sort(pl, right);
	}
	if (pr > left) {
		sort(left, pr);
	}
}

void setNum() {//가중치만큼 최대 10개를 더해 가중치가 큰 순서대로 9부터 곱해서 더함
	int i, sum = 0, s = 9;
	for (i = 0; i <10; i++) {
		sum += (s * num[25-i]);
		s--;
	}
	printf("%d", sum);
}

void finish() {
	free(num);
}