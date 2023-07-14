#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//동적 배열 할당 및 입력
int FillTile(int);
//타일의 개수 반환. 타일을 까는 경우의 수는 n-2까지 깔고 2*1 타일 2개 혹은 2*2타일 하나를 추가하는 경우와, n-1까지 깔고 1*2 타일 하나를 추가하는 경우
void finish();//동적해제

int n;
int* list;

int main() {
	init();
	printf("%d", FillTile(n));
	finish();

	return 0;
}


void init() {
	scanf("%d", &n);
	list = (int*)calloc(n+1, sizeof(int));
	list[0] = 1;
	list[1] = 1;
}

int FillTile(int a) {
	int n1, n2;
	if (a == 1) {//하나의 경우
		return 1;
	}
	if (list[a - 1] != 0) {//저장된 경우의 수라면
		n2 = list[a - 1];
	}
	else {//저장되지 않은 경우의 수라면
		n2=FillTile(a - 1);//n-1개 깔았을 때 경우의 수를 구함
		list[a - 1] = n2;//배열에 저장
	}
	if (list[a - 2] != 0) {//저장된 경우의 수라면
		n1 = list[a - 2];
	}
	else {//저장되지 않은 경우의 수라면
		n1 = FillTile(a - 2);//n-2개 깔았을 때 경우의 수를 구함
		list[a - 2] = n1;//배열에 저장
	}
	list[a] = (n1*2 + n2)%10007;//두 경우의 수를 합하여 10007로 나누어 저장. n1은 2*1 2개 혹은 2*2 하나가 될 수 있으므로 2로 곱함
	return list[a];
}


void finish() {
	free(list);
}
