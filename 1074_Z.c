#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void init();
int visiting();

int n, r, c;
int count = 0;
int main() {
	init();
	printf("%d", visiting());

	return 0;
}

void init() {
	scanf("%d %d %d", &n, &r, &c);
	n = pow(2, n);//n�� �� ���� ����
}

int visiting() {
	int p, q,sec;
	if (n == 1||(r==0&&c==0)) {//�ش� ��ġ�� ã���� �ϴ� ��
		return count;
	}
	else {//����� 4��� �Ѵ�
		p = (r / (n / 2));//0�̸� ����, 1�̸� �Ʒ���
		q = (c / (n / 2));//0�̸� ����, 1�̸� ������
	}
	
	n = n/2;//4��� ������, ��� �� ���� ����
	if (p == 0) {
		if (q == 0) {//1��и�
			sec = 0;
		}
		else {//2��и�
			sec = 1;
			c -= n;
		}
	}
	else {
		if (q == 0) {//3��и�
			sec = 2;
		}
		else {//4��и�
			sec = 3;
			c -= n;
		}
		r -= n;
	}//c-=n�� r-=n�� 4��� ���� ��, �ش� ��ǥ�� ��ġ�ϴ� �κ��� ù ���Ұ� (0,0)�� �ǵ��� ��
	count += sec * pow(n,2); //1,2,3,4�и��� ���ʷ� �̵��ϸ鼭 ���� sec���� �̵��� Ƚ��, ���� ��� sec�� 3�̸�, 1,2,3�и��� ��� �̵��Ͽ����Ƿ� 3*(�� ������ ũ��)
	return visiting();//4��� �� ��Ŀ� ���� Ž�� �ǽ�
}