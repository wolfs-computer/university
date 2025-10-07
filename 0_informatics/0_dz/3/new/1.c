#include <stdio.h>
#include <math.h>



int main() {

    char s[] = "sdll!";

    for (int i = 0; s[i]; i++) {
        printf("%c", s[i]);
        if (s[i + 1]) printf(" ");
    }
    printf("\n");


    return 0;
}

