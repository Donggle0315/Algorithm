#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//n���� �Է� �޾� n*n�� ����� ���� ��, ���� ���� �Է¹޴´�.
int** ListInit(int);
//�Է¹��� n���� ���� n*n����� �����Ѵ�. 
int findSecond(int**,int,int);
//�Է¹��� row,col���� �������� 2*2��� ������ 2������ ū ���� ��ȯ�Ѵ�.
int cal(int**, int);
//n/2*n/2ũ���� ����� �����ѵ�, n*n����� cal �Լ��� ���� ���� ���Ͽ� n/2*n/2��Ŀ� �����Ѵ�. ���������� �ǽ��ϸ�  1*1����� �����Ǿ��� ��� �ش� ���� ��ȯ�Ѵ�.
void finish(int**,int);
//�Է¹��� n���� ���� n*n����� ���������Ѵ�.


int num;//�ʱ� ����� n��
int** list;//�ʱ� ���



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
	return tmp;//n*n����� �ּҰ� ��ȯ
}

int findSecond(int** matrix, int row, int col) {
	int i=row, j=col;
	//���� ū �� Ž��
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
	matrix[i][j] = -10001;//���� ū ���� ���� ���� ���� -1�� �ٲ�
	i = row;
	j = col;
	//���� ū ���� �ٽ� Ž���ϸ�, 2��°�� ū ���� Ž����.
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
	return matrix[i][j];//�ι�°�� ū �� ��ȯ
}

int cal(int** matrix, int depth) {
	int i, j,re;
	int** new_list = ListInit(depth/2);//n/2ũ���� ��� ���� �Ҵ�
	for (i = 0; i < depth / 2; i++) {
		for (j = 0; j < depth / 2; j++) {
			//2*2��ķ� �ɰ��� �ι�°�� ���� ���� findSecond�Լ��� ã�� ���ο� ��Ŀ� ����
			new_list[i][j] = findSecond(matrix, 2 * i, 2 * j);
		}
	}
	if (depth == 2) {//depth==2�̸� 1*1����� �����ǰ�, �ش� ���� re�� ����
		re = new_list[0][0];
	}
	else {//depth>2�̸�, depth/2�� ũ��� ������ �����ϹǷ�, cal�Լ� ��� ȣ��
		re= cal(new_list, depth / 2);
	}
	finish(new_list, depth / 2);//���� ���� �迭 ���� ����
	return re;//1*1��Ŀ����� ���� ��ȯ��
}

void finish(int** matrix,int n) {
	int i;
	for (i = 0; i < n; i++) {
		free(matrix[i]);
	}
	free(matrix);
}
