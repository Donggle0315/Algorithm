#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
//�Է�
void backtracking(int);
//��Ʈ��ŷ���� 0�� ���� ���ڸ� ä������. �� ä�������� ���
int isHere(int,int);
//���ڰ� �� �� �ִ� �� ����
void printing();
//���

int sdoku[9][9];//������ ��
int blank[81][2];//0���� �� �� ��ǥ
int count = 0;//0���� �� ����
int flag = 0;//��� ����

int main() {
	init();
	backtracking(0);

	return 0;
}

void backtracking(int depth) {
	int i;
	if (depth == count) {//0�� �� ä���ٸ�
		flag = 1;//��¿��� 
		printing();//���
		return;
	}
	for (i = 1; i <= 9; i++) {//1���� 9������ ����
		if (flag==0&&isHere(depth, i) == 1) {//����� ���߰�, i�� �� �� ������
			sdoku[blank[depth][0]][blank[depth][1]] = i;//i�Է�
			backtracking(depth + 1);//���� �� ����
			sdoku[blank[depth][0]][blank[depth][1]] = 0;//i����
		}
	}
}

int isHere(int b, int k) {
	int i,j;
	for (i = 0; i < 9; i++) {//���� �࿡ ����
		if (sdoku[i][blank[b][1]] == k) {//���� ���� �ִٸ�
			return 0;
		}
	}
	for (i = 0; i < 9; i++) {//���� ���� ����
		if (sdoku[blank[b][0]][i] == k) {//���� ���� �ִٸ�
			return 0;
		}
	}
	for (i = blank[b][0] / 3 * 3; i < blank[b][0] / 3 * 3 + 3; i++) {//���� 3*3ĭ�� ����
		for (j = blank[b][1] / 3 * 3; j < blank[b][1] / 3 * 3 + 3; j++) {
			if (sdoku[i][j] == k) {//���� ���� �ִٸ�
				return 0;
			}
		}
	}
	//�� �� ����
	return 1;
}



void printing() {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", sdoku[i][j]);
		}
		printf("\n");
	}
}

void init() {
	int i, j;
	for (i = 0; i < 9; i++) {
		for(j=0;j<9;j++){
			scanf("%d", &sdoku[i][j]);
			if (sdoku[i][j] == 0) {//0�� ��ǥ �Է�
				blank[count][0] = i;
				blank[count++][1] = j;				
			}
		}
	}
}