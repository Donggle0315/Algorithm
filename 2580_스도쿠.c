#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void init();
//입력
void backtracking(int);
//벡트레킹으로 0인 곳에 숫자를 채워넣음. 다 채워넣으면 출력
int isHere(int,int);
//숫자가 들어갈 수 있는 지 조사
void printing();
//출력

int sdoku[9][9];//스도쿠 판
int blank[81][2];//0으로 된 곳 좌표
int count = 0;//0으로 된 개수
int flag = 0;//출력 여부

int main() {
	init();
	backtracking(0);

	return 0;
}

void backtracking(int depth) {
	int i;
	if (depth == count) {//0을 다 채웠다면
		flag = 1;//출력여부 
		printing();//출력
		return;
	}
	for (i = 1; i <= 9; i++) {//1부터 9까지에 대해
		if (flag==0&&isHere(depth, i) == 1) {//출력을 안했고, i가 들어갈 수 있으면
			sdoku[blank[depth][0]][blank[depth][1]] = i;//i입력
			backtracking(depth + 1);//다음 수 조사
			sdoku[blank[depth][0]][blank[depth][1]] = 0;//i제거
		}
	}
}

int isHere(int b, int k) {
	int i,j;
	for (i = 0; i < 9; i++) {//같은 행에 대해
		if (sdoku[i][blank[b][1]] == k) {//같은 수가 있다면
			return 0;
		}
	}
	for (i = 0; i < 9; i++) {//같은 열에 대해
		if (sdoku[blank[b][0]][i] == k) {//같은 수가 있다면
			return 0;
		}
	}
	for (i = blank[b][0] / 3 * 3; i < blank[b][0] / 3 * 3 + 3; i++) {//같은 3*3칸에 대해
		for (j = blank[b][1] / 3 * 3; j < blank[b][1] / 3 * 3 + 3; j++) {
			if (sdoku[i][j] == k) {//같은 수가 있다면
				return 0;
			}
		}
	}
	//들어갈 수 있음
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
			if (sdoku[i][j] == 0) {//0의 좌표 입력
				blank[count][0] = i;
				blank[count++][1] = j;				
			}
		}
	}
}