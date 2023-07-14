#include <stdio.h>

int main() {
	int tmp1,tmp2,num,count=0;
	scanf("%d",&num);
	tmp1=num;
	while(1){
		count++;
		tmp2=10*(tmp1%10);
		tmp2+=(tmp1/10+tmp1%10)%10;
		tmp1=tmp2;
		if(tmp1==num) break;
	}
	printf("%d",count);
	return 0;
}
