#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//n값을 입력 받아 n*n의 행렬을 만든 뒤, 원소 값을 입력받는다.
int** ListInit(int);
//입력받은 n값에 대한 n*n행렬을 생성한다. 
int findSecond(int**,int,int);
//입력받은 row,col값을 기준으로 2*2행렬 내에서 2번쨰로 큰 수를 반환한다.
int cal(int**, int);
//n/2*n/2크기의 행렬을 생성한뒤, n*n행렬을 cal 함수를 통해 값을 구하여 n/2*n/2행렬에 저장한다. 분할정복을 실시하며  1*1행렬이 생성되었을 경우 해당 값을 반환한다.
void finish(int**,int);
//입력받은 n값에 대한 n*n행렬을 동적해제한다.


int num;//초기 행렬의 n값
int** list;//초기 행렬



int main() {
	init();

	printf("%d", cal(list, num));
	finish(list, num);

	return 0;
}

void init() {
	int i,j;
	scanf("%d", &num);
	list = (int**)malloc(num * sizeof(int*));
	for (i = 0; i < num; i++) {
		list[i] = (int*)malloc(num * sizeof(int));
		for (j = 0; j < num; j++) {
			scanf("%d", &list[i][j]);
		}
	}
}

int** ListInit(int n) {
	int i;
	int** tmp = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		tmp[i] = (int*)malloc(n * sizeof(int));
	}
	return tmp;//n*n행렬의 주소값 반환
}

int findSecond(int** matrix, int row, int col) {
	int i=row, j=col;
	//가장 큰 수 탐색
	if (matrix[row][col + 1] >= matrix[i][j]) {
		i = row;
		j = col+1;
	}
	if (matrix[row+1][col] >= matrix[i][j]) {
		i = row + 1;
		j = col;
	}
	if (matrix[row+1][col + 1] >= matrix[i][j]) {
		i= row + 1;
		j = col + 1;
	}
	matrix[i][j] = -10001;//가장 큰 수를 가장 작은 범위 -1로 바꿈
	i = row;
	j = col;
	//가장 큰 수를 다시 탐색하면, 2번째로 큰 수가 탐색됨.
	if (matrix[row][col + 1] >= matrix[i][j]) {
		i = row;
		j = col + 1;
	}
	if (matrix[row + 1][col] >= matrix[i][j]) {
		i = row + 1;
		j = col;
	}
	if (matrix[row + 1][col + 1] >= matrix[i][j]) {
		i = row + 1;
		j = col + 1;
	}
	return matrix[i][j];//두번째로 큰 수 반환
}

int cal(int** matrix, int depth) {
	int i, j,re;
	int** new_list = ListInit(depth/2);//n/2크기의 행렬 동적 할당
	for (i = 0; i < depth / 2; i++) {
		for (j = 0; j < depth / 2; j++) {
			//2*2행렬로 쪼개어 두번째로 작은 수를 findSecond함수로 찾고 새로운 행렬에 저장
			new_list[i][j] = findSecond(matrix, 2 * i, 2 * j);
		}
	}
	if (depth == 2) {//depth==2이면 1*1행렬이 생성되고, 해당 값을 re에 저장
		re = new_list[0][0];
	}
	else {//depth>2이면, depth/2의 크기로 분할이 가능하므로, cal함수 재귀 호출
		re= cal(new_list, depth / 2);
	}
	finish(new_list, depth / 2);//새로 만든 배열 동적 해제
	return re;//1*1행렬에서의 값이 반환됨
}

void finish(int** matrix,int n) {
	int i;
	for (i = 0; i < n; i++) {
		free(matrix[i]);
	}
	free(matrix);
}
