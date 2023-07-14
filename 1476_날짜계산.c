#include <stdio.h>
#include <stdlib.h>

void init();
void finish();

int e,s,m;
int year;

int main(){
    init();
    while(1){
        if((year%15)+1==e&&(year%28)+1==s&&(year%19)+1==m) break;
        else year++;
    }
    finish();

    return 0;
}

void init(){
    scanf("%d %d %d",&e,&s,&m);
    year=0;
}

void finish(){
    printf("%d\n",year+1);
}
