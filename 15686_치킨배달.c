#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void init();
//�Է� �� ġŲ���� ���� ��ǥ ����
void backtracking(int, int);
//��Ʈ��ŷ�� �̿��Ͽ� ����� ���Ը� �����ϰ� �� �����Ű�� �Ÿ� ����
void findMinDistance();
//��� ���� �Ÿ��� �� �� �ּҸ� ����
int nearStore(int);
//�ϳ��� ���� ���� �ּ� �Ÿ� ��ȯ

int n, m;
int list[51][51];//����
int store[14][2];//���� ��ǥ
int house[101][2];//�� ��ǥ
int h = 0;//���� ����
int s = 0;//���� ����
int min = 0;//�Ÿ��� �ּڰ�

int main() {
	init();
	backtracking(-1, 0);
	printf("%d", min);

	return 0;
}

void findMinDistance() {
	int sum = 0;
	int i;
	for (i = 0; i < h; i++) {//��� ���� ����
		sum += nearStore(i);//�ּ� �Ÿ��� ��
	}
	if (min == 0) {
		min = sum;
	}
	else if (sum < min) {//�ּ� �Ÿ��� ���� �ּҶ��
		min = sum;
	}
}

int nearStore(int k) {
	int x, y;
	int i;
	int p =0;
	x = house[k][0];//���� ��ǥ
	y = house[k][1];
	for (i = 0; i < s; i++) {//��� ���Կ� ����
		if (store[i][0] == -1) {//����� ���Զ��
			continue;
		}
		if (p == 0) {//������ ���Ա����� �Ÿ��� �ּҸ� p�� ����
			p = abs(x - store[i][0]) + abs(y - store[i][1]);
		}
		else if(abs(x-store[i][0])+abs(y-store[i][1])<p){
			p = abs(x - store[i][0]) + abs(y - store[i][1]);
		}

	}
	return p;
}

void backtracking(int si, int depth) {
	int i,p,q;
	if (depth == s - m) {//���游ŭ ����ٸ�
		findMinDistance();//�Ÿ� ����
		return;
	}
	for (i = si + 1; i < s; i++) {//��� ���Կ� ����
		p = store[i][0];
		q = store[i][1];
		store[i][0] = -1;//���� ���
		store[i][1] = -1;
		backtracking(i, depth + 1);//���� ���� ����
		store[i][0] = p;//����� ���� ����
		store[i][1] = q;
	}
}

void init() {
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &list[i][j]);
			if (list[i][j] == 2) {//ġŲ�� ��ǥ ����
				store[s][0] = i;
				store[s++][1] = j;
			}
			if (list[i][j] == 1) {//�� ��ǥ ����
				house[h][0] = i;
				house[h++][1] = j;
			}
		}
	}
}