#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
//�Է� �� ������ ��ǥ ����
void backtracking(int, int, int);
//��Ʈ��ŷ�� ����Ͽ� ���� ����. 3���� ���� ����� ���������� �ɸ����� ����
void print();
//����� YES||NO�� ���
int AvoidMonitor();
//���ô��ϴ��� ���� ���ô��Ѵٸ� 1�� �ƴ϶�� 0�� ��ȯ
int teacherMonitor(int, int);
//������ �Ѹ��� ���ø� ����. �����ϴ� �л��� �ִٸ� 1�� �ƴ϶�� 0�� ��ȯ

int n;
char list[10][10];//����
int flag = 0;//���ÿ���. �������� �ʴ� ��찡 �ִٸ� 1
int teacher[10][2];//�������� ��ǥ
int nt = 0;//�����Լ�

int main() {
	init();
	backtracking(0, -1, 0);
	print();
	return 0;
}

void print() {
	if (flag == 1) {
		printf("YES");
	}
	else {
		printf("NO");
	}
}

int AvoidMonitor() {
	int i;
	for (i = 0; i < nt; i++) {//��� �����Կ� ����
		if (teacherMonitor(teacher[i][0], teacher[i][1]) == 1) {//�����ϴ� �л��� �ִٸ�
			return 1;
		}
	}//��� �������� �����ϴ� �л��� ���ٸ�
	return 0;
}

int teacherMonitor(int si, int sj) {
	int i,ni,nj;
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿� ���⿡ ����
	for (i = 0; i < 4; i++) {
		ni = si;
		nj = sj;
		while (1) {
			ni += dir[i][0];
			nj += dir[i][1];
			if (ni<0 || ni>n - 1 || nj<0 || nj>n - 1 || list[ni][nj] == 'W') {//���� ���������ų� ���� ���� ���
				break;
			}
			if (list[ni][nj] == 'S') {//�л��� �����Ѵٸ�
				return 1;
			}
		}
	}//�����ϴ� �л��� ���ٸ�
	return 0;
}

void backtracking(int si,int sj,int depth) {
	int i, j;
	if (depth == 3) {//3���� ���� �����ٸ�
		if (AvoidMonitor() == 0) {//�����ϴ� �л��� ���ٸ�
			flag = 1;
		}
		return;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i < si) {//������ �̹� ����
				continue;
			}
			if (i == si && j <= sj) {//������ �̹� ����
				continue;
			}
			if (list[i][j] == 'X') {//���� ���� �� �ִ� �����̶��
				list[i][j] = 'W';//���� �����
				backtracking(i, j, depth + 1);//���� ��� ����
				list[i][j] = 'X';//���� �ٽ� ����
			}
		}
	}
}


void init() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf(" %c", &list[i][j]);
			if (list[i][j] == 'T') {//�������� ��ǥ ����
				teacher[nt][0] = i;
				teacher[nt++][1] = j;
			}
		}
	}
}
