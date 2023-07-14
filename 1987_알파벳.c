#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
//�Է�
void backtracking(int, int, int);
//��Ʈ��ŷ�� ����Ͽ� ���� ������ �� �ִ� �������� �̵��ϰ� �ִ� �Ÿ� �ʱ�ȭ

char list[21][21];//�����ǿ� ���ĺ� ����
int r, c;//���� r ���� c
int max = 0;//�ִ� �̵� �Ÿ�
int isvisited[26] = { 0 };//�ش� ���ĺ� �湮 ����


int main() {
	init();
	isvisited[list[0][0] - 'A'] = 1;//ó�� �����ϴ� �κ��� �湮�� ������ ǥ��
	backtracking(0, 0, 1);
	printf("%d", max);

	return 0;
}

void backtracking(int si, int sj, int depth) {
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿� ����
	int i,p,q;
	
	if (depth > max) {//�ش� �̵��Ÿ��� �ִ��� ��
		max = depth;
	}

	for (i = 0; i < 4; i++) {//�����¿쿡 ����
		p = si + dir[i][0];
		q = sj + dir[i][1];
		if (p >= r || p < 0) {//���� ��
			continue;
		}
		if (q >= c || q < 0) {//���� ��
			continue;
		}
		if (isvisited[list[p][q]-'A'] == 1) {//�̹� �湮�� ���ĺ��̶��
			continue;
		}
		isvisited[list[p][q]-'A'] = 1;//�ش� ���ĺ��� �湮
		backtracking(p, q, depth + 1);//���� ���̷� Ž��
		isvisited[list[p][q]-'A'] = 0;//���ĺ� �湮 ���
	}	
	
}

void init() {
	int i, j;
	char str[21];
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++) {
		scanf("%s", str);
		for (j = 0; j < c; j++) {
			list[i][j] = str[j];
		}
	}

}