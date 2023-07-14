#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//동적 할당 및 입력
void finish();
//동적 해제
void reverseOri(int, int);
//입력 받은 범위의 3*3만큼 reverse
int checking();
//배열의 원소가 다르면 해당 인덱스의 3*3만큼 reverse, ori와 ans가 같다면 reverse한 횟수 반환
int isEqual();
//ori와 ans가 같으면 1, 다르면 -1 반환

int n, m;
int** ori;
int** res;

int main(){
	init();
	printf("%d", checking());
	finish();

	return 0;
}

void init() {
	int i,j;
	char* str;
	scanf("%d %d", &n, &m);
	ori = (int**)malloc(n * sizeof(int*));
	res = (int**)malloc(n * sizeof(int*));
	str = (char*)malloc((m + 1) * sizeof(int));
	for (i = 0; i < n; i++) {
		ori[i] = (int*)malloc(m * sizeof(int));
		res[i] = (int*)malloc(m * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		for (j = 0; j < m; j++) {
			ori[i][j] = str[j] - '0';
		}
	}
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		for (j = 0; j < m; j++) {
			res[i][j] = str[j] - '0';
		}
	}
	free(str);
}

void finish() {
	int i;
	for (i = 0; i < n; i++) {
		free(ori[i]);
		free(res[i]);
	}
	free(ori);
	free(res);
}

void reverseOri(int r, int c) {
	int i, j;
	for (i = r; i < r + 3; i++) {//r,c를 기점으로 3*3만큼 reverse
		for (j = c; j < c + 3; j++) {
			if (ori[i][j] == 0) {
				ori[i][j] = 1;
			}
			else {
				ori[i][j] = 0;
			}
		}
	}
}

int checking() {
	int num = 0;//뒤집은 횟수
	int i, j;
	if (n < 3 || m < 3) {
		if (isEqual() == 1) {//3*3 미만이지만 배열이 같다면
			return 0;//0번 뒤집음
		}
		return -1;//불가능
	}
	for (i = 0; i < n - 2; i++) {
		for (j = 0; j < m - 2; j++) {
			if (ori[i][j] != res[i][j]) {//i,j 배열의 값이 다르다면
				reverseOri(i, j);//i,j를 기준으로 reverse
				num++;//뒤집은 횟수 ++
				if (isEqual() == 1) {//배열이 같아졌다면
					return num;
				}
			}
		}
	}
	return -1;//끝까지 바꿨는데도 배열이 다르다면
}

int isEqual() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (ori[i][j] != res[i][j]) {//배열이 다르다면
				return -1;
			}
		}
	}
	return 1;//배열이 같다면
}