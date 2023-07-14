#include <stdio.h>
#include <stdlib.h>

//위 w, 아래 y, 앞 r, 뒤 o, 왼쪽 r, 오른쪽 b

void init();

char cube[6][3][3];
char color[6]={'w','y','r','o','r','b'};
int main(){



	return 0;
}

void init(){
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				cube[i][j][k]=color[i];
			}
		}
	}
}

void commandU(char dir){
	char tmp[3][3];
	if(dir=='-'){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				tmp[j][2-i]=cube[0][i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cube[0][i][j]=tmp[i][j];
			}
		}
		for(int i=0;i<3;i++){
			char
		}
	}
}