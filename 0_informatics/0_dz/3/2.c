#include <stdio.h>




int main() {

    int n1 = 3;
    int n2 = 6;
    char s1[] = "abcd";
    char s2[] = "hjkl999";


    int len1 = 0;
    while (s1[len1]) len1++;
    // printf("%d\n", len1);

    int len2 = 0;
    while (s2[len2]) len2++;
    // printf("%d\n", len2);

    for (int i = 0; i < n1 && i < len1; i++) {
        printf("%c", s1[i]);
    }
    for (int i = len2 - n2; i < n2 && i < len2; i++) {
        printf("%c", s2[i]);
    }
    printf("\n");



    return 0;
}

