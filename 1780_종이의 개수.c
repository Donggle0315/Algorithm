#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init(int);//matrix 배열 동적할당 및 원소 입력 후 저장하는 함수
void finish(int);//matrix 배열 동적할당 해제하는 함수
void printing();//-1,0,1로 채워진 종이의 개수 출력하는 함수
void re_counting(int, int, int);//행렬에 저장된 종이를 잘라 -1,0,1로만 채워진 종이의 개수를 구해내는 함수

int** matrix;//N*N크기의 행렬
int n1 = 0, n2 = 0, n3 = 0;//n1은 -1, n2는 0, n3는 1로 이루어진 종이의 개수

int main() {
	int num;

	scanf("%d", &num);
	init(num);
	re_counting(0, 0, num);
	printing();
	finish(num);

	return 0;
}

void init(int num) {
	int i, j;
	matrix = (int**)malloc(num * sizeof(int*));
	for (i = 0; i < num; i++) {
		matrix[i] = (int*)malloc(num * sizeof(int));
	}
	//동적할당
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	//원소 입력 및 저장
}

void finish(int num) {
	int i;
	for (i = 0; i < num; i++) {
		free(matrix[i]);
	}
	free(matrix);
	//동적 할당 해제
}

void printing() {
	printf("%d\n", n1);
	printf("%d\n", n2);
	printf("%d\n", n3);
	//출력
}


void re_counting(int row, int col, int n) {//row와 col은 시작 위치, n은 행과 열의 개수
	int i, j, k = matrix[row][col],new_n = n / 3, flag = 0; //k는 행렬의 첫 원소, new_n은 다음 재귀의 인자, flag는 1일때 모두 같은 수가 아닌 경우, 0일때 모두 같은 수 인 경우
	if (n == 1) { //n이 1이면 검사할 필요 없이 모두 같은 수
		switch (k) {
			case -1:
				n1++;
				break;
			case 0:
				n2++;
				break;
			case 1:
				n3++;
		}
		return;//함수 종료
	}
	for (i = row; i < row + n; i++) {
		for (j = col; j < col + n; j++) {
			if (matrix[i][j] != k) { //종이가 모두 같은 수가 아닐 경우
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	if (flag == 0) { //종이가 모두 같은 수 일 경우
		switch (k) {
			case -1:
				n1++;
				break;
			case 0:
				n2++;
				break;
			case 1:
				n3++;
		}
	}
	else { // 종이가 모두 같은 수가 아닐 경우 
		for (i = 0; i < 3; i++) { 
			for (j = 0; j < 3; j++) { //9등분하여 함수 재귀 호출
				re_counting(row + i * new_n, col + j * new_n, new_n);
			}
		}
	}
}