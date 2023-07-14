#include <stdio.h>

int main(void){
    int num;
    int count=0;
    scanf("%d",&num);
    for(int i=1;i<=num;i*=10){
        count+=num-i+1;
    }
    printf("%d\n",count);
    return 0;
}