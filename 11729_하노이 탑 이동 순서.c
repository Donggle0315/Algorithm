#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void HanoiTowerCount(int, int, int, int);//�ϳ��� Ÿ�� �̵� Ƚ���� ���� �Լ�
void HanoiTower(int, int, int, int);//�ϳ��� Ÿ�� �̵� ��θ� ����ϴ� �Լ�

int count = 0;

int main() {

	int num;//������ ����
	scanf("%d", &num);
	HanoiTowerCount(num,1,2,3);//�ϳ��� Ÿ�� �̵� Ƚ���� ���� count������ ����
	printf("%d\n", count);
	HanoiTower(num, 1, 2, 3);//�ϳ��� Ÿ�� �̵� ��θ� ���

	return 0;
}

void HanoiTowerCount(int num, int from, int by, int to) {
	if (num == 1) {
		count++;//�ű�� Ƚ��
	}
	else {
		HanoiTowerCount(num - 1, from, to, by);
		count++;//�ű�� Ƚ��
		HanoiTowerCount(num - 1, by, from, to);
	}
}

void HanoiTower(int num, int from, int by, int to) {
	if (num == 1) {//�̵��� ������ ������ 1���� ��
		printf("%d %d\n", from, to);//from���� to������ ���� 1���� �̵��ϴ°� from->to�� �ٷ� �ű�� �ǹǷ� count++
	}
	else {
		HanoiTower(num - 1, from, to, by);//���� n�� �� ���� ���� n-1���� from���� by�� �ű�� ����
		printf("%d %d\n", from, to);//ū ���� 1���� from���� to�� �ű�� ������ �ѹ��̸� ��.
		HanoiTower(num - 1, by, from, to);//by�� �����ߴ� ���� n-1���� to�� �ű�� ����
	}
}