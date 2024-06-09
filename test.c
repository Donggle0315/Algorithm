#include <stdio.h>
#include <math.h>

int main() {
    FILE *inPt = fopen("temp.txt", "r");
    char ch;
    while ((ch = fgetc(inPt)) != EOF) {
        printf("%c\n",ch);
    }

    return 0;

}