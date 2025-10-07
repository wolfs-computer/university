#include <stdio.h>




int main() {

    int n1 = 1;
    int n2 = 1;
    char s1[] = "abcd";
    char s2[] = "hjkl999";


    int len1 = 0;
    while (s1[len1]) len1++;

    int len2 = 0;
    while (s2[len2]) len2++;

    for (int i = 0; i < n1 && i < len1; i++) {
        printf("%c", s1[i]);
    }

    int start = len2 - n2;
    if (start < 0) start = 0;

    for (int i = start; i < len2; i++) {
        printf("%c", s2[i]);
    }
    printf("\n");



    return 0;
}

