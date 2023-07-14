#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void init();
void finish();
int findMaxSum();
int case1();
int case2();
int case3();
int case4();
int case5();
int case6();
int case7();


int n, m;
int** list;

int main() {
	init();
	printf("%d\n", findMaxSum());
	finish();
	

	return 0;
}

int case1() {
	int max = 0;
	int tmp;
	for (int i = 0; i < n-3; i++) {
		for (int j = 0; j < m; j++) {
			tmp = list[i][j] + list[i + 1][j] + list[i + 2][j] + list[i + 3][j];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	け
	け
	け
	け
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-3; j++) {
			tmp = list[i][j] + list[i][j+1] + list[i][j+2] + list[i][j+3];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*けけけけ*/
	return max;
}

int case2() {
	int max = 0;
	int tmp;
	for (int i = 0; i < n - 1; i++) {
		for(int j=0;j<m-1;j++){
			tmp = list[i][j] + list[i][j + 1] + list[i + 1][j] + list[i + 1][j + 1];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	けけ
	けけ
	*/
	return max;
}

int case3() {
	int max = 0;
	int tmp;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = list[i][j]+list[i+1][j]+list[i+2][j]+list[i+2][j+1];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	け
	け
	けけ
	*/
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = list[i+1][j]+list[i+1][j+1]+list[i+1][j+2]+list[i][j+2];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	   け
	けけけ
	*/
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = list[i][j] + list[i][j + 1] + list[i+1][j+1]+list[i + 2][j + 1] ;
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	けけ
	  け
	  け
	*/
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = list[i][j] + list[i][j + 1] + list[i][j+2] + list[i + 1][j];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	けけけ
	け
	*/

	return max;
}

int case4() {
	int max = 0;
	int tmp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = list[i+1][j] + list[i + 1][j+1] + list[i][j+1] + list[i][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	  けけ
	けけ
	*/
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = list[i][j] + list[i + 1][j] + list[i + 1][j+1] + list[i + 2][j +1];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	け
	けけ
	 け
	*/
	return max;
}

int case5() {
	int max = 0;
	int tmp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = list[i][j+1] + list[i + 1][j] + list[i+1][j + 1] + list[i+1][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	  け
	けけけ
	*/

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = list[i][j] + list[i][j + 1] + list[i][j + 2] + list[i+1][j + 1];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	けけけ
	  け
	*/

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = list[i][j] + list[i + 1][j] + list[i+2][j] + list[i+1][j+1];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	 け
	 けけ
	 け
	*/

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = list[i + 1][j] + list[i][j + 1] + list[i+1][j + 1] + list[i+2][j +1];
			if (tmp > max) {
				max = tmp;
			}
		}
		
	}
	/*
	  け
	けけ
	  け
	*/
	return max;
}

int case6() {
	int max = 0;
	int tmp;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = list[i][j+1] + list[i + 1][j+1] + list[i + 2][j+1] + list[i + 2][j];
			if (tmp > max) {
				max = tmp;
			}
		}

	}
	/*
      け
	  け
	けけ
	*/
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = list[i][j] + list[i + 1][j] + list[i + 1][j + 1] + list[i+1][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}

	}
	/*
	け
	けけけ
	*/
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = list[i][j] + list[i][j + 1] + list[i + 1][j] + list[i + 2][j];
			if (tmp > max) {
				max = tmp;
			}
		}

	}
	/*
	けけ
	け
	け
	*/
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = list[i][j] + list[i][j + 1] + list[i][j + 2] + list[i + 1][j+2];
			if (tmp > max) {
				max = tmp;
			}
		}

	}
	/*
	けけけ
	    け
	*/

	return max;
}

int case7() {
	int max = 0;
	int tmp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = list[i][j] + list[i][j + 1] + list[i+1][j + 1] + list[i+1][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}

	}
	/*
	けけ
	  けけ
	*/
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = list[i][j+1] + list[i + 1][j] + list[i + 1][j + 1] + list[i+2][j];
			if (tmp > max) {
				max = tmp;
			}
		}

	}
	/*
 	  け
	けけ
	け
	*/
	return max;
}


int findMaxSum() {
	int max = case1();
	int k=case2();
	if (k > max) {
		max = k;
	}
	k = case3();
	if (k > max) {
		max = k;
	}
	k = case4();
	if (k > max) {
		max = k;
	}
	k = case5();
	if (k > max) {
		max = k;
	}
	k = case6();
	if (k > max) {
		max = k;
	}
	k = case7();
	if (k > max) {
		max = k;
	}

	return max;
}

void init() {
	scanf("%d %d", &n, &m);
	list = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		list[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++) {
			scanf("%d", &list[i][j]);
		}
	}
}

void finish() {
	for (int i = 0; i < n; i++) {
		free(list[i]);
	}
	free(list);
}