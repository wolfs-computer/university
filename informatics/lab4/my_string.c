#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"



size_t my_strlen(const char *s) {
    int res = 0;

    while (*s) {
        ++s;
        ++res;
    }

    return res;
}


char *my_strcpy(char *dest, const char *src) {
    int i = 0;
    
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }

    return dest;
}


char *my_strcat(char *dest, const char *src) {
    char *ptr = dest;
    
    while (*dest) dest++;

    while ((*dest++ = *src++));

    return ptr;
}


int check_delim(const char *delim, const char c) {
    while (*delim) {
        if (*delim == c) return 1;
        delim++;
    }
    return 0;
}


char *my_strtok(char *s, const char *delim) {

    static char* str;

    if (s != NULL) str = s;

    if (!delim || *str == '\0') return NULL;


    while (*str != '\0' && check_delim(delim, *str)) str++;

    if (*str == '\0') return NULL;
    // now on first char of token


    char *token = str;
    str++;

    while (*str != '\0' && !check_delim(delim, *str)) str++;
    // start of delim or \0

    if (*str != '\0') {
        *str = '\0';
        str++;
    }

    return token;
}


// // DEBUG
// int main() {
//
//     char a[] = "1234";
//     printf("strlen: %i (4)\n", (int) my_strlen(a));
//
//     char b[] = "0000";
//     printf("strcpy: %s %s (1234)\n", b, my_strcpy(b, a));
//
//     char *c = (char*) malloc(9 * sizeof(char));
//     c[0] = 'a';
//     c[1] = 'b';
//     c[2] = 'c';
//     c[3] = 'd';
//     c[4] = '\0';
//     char d[] = "9876";
//     printf("strcat: %s %s %s (abcd9876)\n", c, d, my_strcat(c, d));
//     free(c);
//
//
//     printf("\nstrtok:\n");
//
//     char *s = (char*) calloc(11, sizeof(char));
//     s[0] = ' ';
//     s[1] = 'a';
//     s[2] = 'a';
//     s[3] = '9';
//     s[4] = '8';
//     s[5] = ' ';
//     s[6] = 'c';
//     s[7] = ' ';
//     s[8] = 'e';
//     s[9] = 'f';
//     s[10] = '\0';
//     printf("\"%s\"\n", s);
//
//     char *word = my_strtok(s, " \t");
//     while (word != NULL) {
//         printf("word: %s\n", word);
//
//         word = my_strtok(NULL, " \t");
//     }
//     free(s);
//     free(word);
//
//
//     char *s2 = (char*) calloc(11, sizeof(char));
//     s2[0] = ' ';
//     s2[1] = 'a';
//     s2[2] = 'a';
//     s2[3] = '9';
//     s2[4] = '8';
//     s2[5] = ' ';
//     s2[6] = 'c';
//     s2[7] = ' ';
//     s2[8] = 'e';
//     s2[9] = 'f';
//     s2[10] = '\0';
//     printf("\"%s\"\n", s2);
//
//     char *word2 = my_strtok(s2, " \t");
//     while (word2 != NULL) {
//         printf("word2: %s\n", word2);
//
//         word2 = my_strtok(NULL, " \t");
//     }
//     free(s2);
//     free(word2);
//
//
//     return 0;
// }
