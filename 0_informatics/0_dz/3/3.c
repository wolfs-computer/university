#include <stdio.h>



int main() {

    char s[] = "abcde1234567890iiiiii";

    for (int i = 0; s[i]; i++) {
        if ((i + 1) % 6 == 3) {
            printf(" ");
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");


    return 0;
}
