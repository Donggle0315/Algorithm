#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void respond(int,int);




int main() {
	int num,depth=0;
	scanf("%d", &num);
	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	respond(num,depth);


	return 0;
}

void respond(int num,int depth) {
	int i;
	for (i = 0; i < depth * 4; i++) {
		printf("_");
	}
	printf("\"����Լ��� ������?\"\n");
	if (num == 0) {
		for (i = 0; i < depth * 4; i++) {
			printf("_");
		}
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
	}
	else {
		for (i = 0; i < depth * 4; i++) {
			printf("_");
		}
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n"); 
		for (i = 0; i < depth * 4; i++) {
			printf("_");
		}
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		for (i = 0; i < depth * 4; i++) {
			printf("_");
		}
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
		respond(num - 1,depth+1);
	}
	for (i = 0; i < depth * 4; i++) {
		printf("_");
	}
	printf("��� �亯�Ͽ���.\n");
}