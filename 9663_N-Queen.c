#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է� �� ���� �Ҵ�
void finish();
//���� ����
void backtracking(int);
//��Ʈ��ŷ���� ���� ��ġ�ϰ� ��� ���� ��ġ �ȴٸ� count++
int isAttack(int,int);
//���� ������ �� ���� ��ġ������ 1, �ϸ� 0 ��ȯ

int n;//���� ����
int* board;//���� ���� ��ǥ�� ����
int count;//������ ����� ��

int main() {
	init();
	backtracking(0);
	printf("%d", count);
	finish();

	return 0;
}



void backtracking(int depth) {//depth�� ���� ���� ����-1���� ���� ���� ���� ��ǥ
	int j;
	if (depth == n) {//�� �����ٸ�
		count++;
		return;
	}
	
	for (j = 0; j < n; j++) {//j���� ���Ͽ�
		if (isAttack(depth,j)==1) {//���� �� �ִٸ�
			board[depth] = j;//���� ����
			backtracking(depth + 1);//���� �� ����
			board[depth] = -1;//�� ����
		}
	}
			
}

int isAttack(int a,int b) {
	int i;
	for (i = 0; i < a; i++) {//���� �࿡ ���Ͽ�
		if (board[i] == b) {//���� ���� ��ġ
			return 0;
		}
		if (i + board[i] == a + b) {//���� ����� �밢���� ��ġ
			return 0;
		}
		if (i - board[i] == a-b) {//���� ������ �밢���� ��ġ
			return 0;
		}
	}//�������� �ʴ� ���
	return 1;
}

void init() {
	int i;
	scanf("%d", &n);
	board = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++) {
		board[i] = -1;
	}
	count = 0;
}

void finish() {
	free(board);
}