#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, flag=0;//1이면 ascending, 2이면 descending, 3이면 mixed
    int* list = (int*)malloc(8 * sizeof(int));
    for (i = 0; i < 8; i++) {
        scanf("%d", &list[i]);
    }
    for (i = 0; i < 8; i++) {
        if (i != 0) {
            if (flag == 0) {
                if (list[i] > list[i - 1]) {
                    flag = 1;
                }
                else {
                    flag = 2;
                }
            }
            else if (flag == 1 && list[i]<list[i - 1] || flag == 2 && list[i]>list[i - 1]) {
                flag = 3;
            }
        }
    }
    switch (flag) {
        case 1:
            printf("ascending");
            break;
        case 2:
            printf("descending");
            break;
        case 3:
            printf("mixed");
    }
    free(list);


    return 0;
}