#include <stdio.h>

int main() {
	//45분 일찍 알림설정하기
	int h,m;
	scanf("%d %d",&h,&m);
	if(m<45){
		if(h==0){
			h+=24;
		}
		h-=1;
		m+=15;
	}
	else{
		m-=45;
	} 
	printf("%d %d",h,m);

	return 0;
}
