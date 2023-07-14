#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void init();
//입력 및 입력받은 알파벳을 오름차순으로 정렬
void backtracking(int,int);
//백트레킹을 사용하여 암호를 구성. 조건에 맞으면 출력
void quicksort(int, int);
//퀵 정렬
void print();
//최소 모음의 개수가 1개, 자음의 개수 2개를 만족하면 출력

int l, c;
char code[15];//암호저장
char list[15];//입력받은 알파벳 저장
int consonant;//자음의 개수
int  vowel;//모음의 개수

int main() {
	init();
	backtracking(-1, 0);

	return 0;
}

void backtracking(int start,int depth) {
	int i;
	if (depth == l) {//암호를 다 채웠다면
		print();//조건에 맞다면 출력
		return;
	}
	for (i = start+1; i < c; i++) {//오름차순으로 정렬된 알파벳에 대해
		if (list[i] == 'a' || list[i] == 'e' || list[i] == 'i'||list[i] == 'o' || list[i] == 'u') {
			vowel++;//모음
		}
		else {
			consonant++;//자음
		}
		code[depth] = list[i];//암호에 입력
		backtracking(i, depth + 1);//다음 순서 조사
		if (list[i] == 'a' || list[i] == 'e' || list[i] == 'i' || list[i] == 'o' || list[i] == 'u') {
			vowel--;//모음 제거
		}
		else {
			consonant--;//자음 제거
		}
	}
}

void print() {
	int i;
	if(consonant<2||vowel<1){//자음 2개 혹은 모음 1개 미만이라면
		return;//출력하지 않음
	}
	for (i = 0; i < l; i++) {//출력
		printf("%c", code[i]);
	}
	printf("\n");
}

void init() {
	int i;
	scanf("%d %d", &l, &c);
	for (i = 0; i < c; i++) {
		scanf(" %c", &list[i]);
	}
	quicksort(0, c - 1);
	consonant = 0;
	vowel = 0;
}

void quicksort(int left, int right) {
	int pl = left;
	int pr = right;
	char x =list[(left + right) / 2];
	char tmp;
	do {
		while (list[pl] < x) {
			pl++;
		}
		while (x < list[pr]) {
			pr--;
		}
		if (pl <= pr) {
			tmp = list[pl];
			list[pl] = list[pr];
			list[pr] = tmp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) {
		quicksort(left, pr);
	}
	if (pl < right) {
		quicksort(pl, right);
	}
}