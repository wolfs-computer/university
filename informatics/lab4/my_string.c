#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"



size_t strlen(const char *s) {
    int res = 0;

    while (*s) {
        ++s;
        ++res;
    }

    return res;
}


char *strcpy(char *dest, const char *src) {
    int i = 0;
    
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }

    return dest;
}


char *strcat(char *dest, const char *src) {
    int i = 0;

    while (dest[i]) i++;

    for (int g = 0; src[g] != '\0'; g++) {
        dest[i + g] = src[g];
    }

    return dest;
}


int check_delim(const char *delim, char c) {
    // printf("!!\n");
    while (*delim != '\0') {
        // printf("-> \'%c\'\n", *delim);
        if (*delim == c) return 1;
        delim++;
    }
    return 0;
}


char *strtok(char *s, const char *delim) {

    static char* str;
    static int s_pos = 0;

    if (s != NULL) {
        str = (char*) calloc(strlen(s) + 1, sizeof(char));
        strcpy(str, s);
    }

    if (!delim || str[s_pos] == '\0') {
        free(str);
        return NULL;
    }


    while (str[s_pos] != '\0' && check_delim(delim, str[s_pos])) s_pos++;

    if (str[s_pos] == '\0') {
        free(str);
        return NULL;
    }
    // now on first char of token


    char *token = str + s_pos;
    s_pos++;

    while (str[s_pos] != '\0' && !check_delim(delim, str[s_pos])) s_pos++;
    // start of delim or \0

    if (str[s_pos] != '\0') {
        str[s_pos] = '\0';
        s_pos++;
    }

    return token;
}


// DEBUG
int main() {

    char a[] = "1234";
    printf("strlen: %i (4)\n", (int) strlen(a));

    char b[] = "0000";
    printf("strcpy: %s %s (1234)\n", b, strcpy(b, a));

    char *c = (char*) malloc(9 * sizeof(char));
    c[0] = 'a';
    c[1] = 'b';
    c[2] = 'c';
    c[3] = 'd';
    c[4] = '\0';
    char d[] = "9876";
    printf("strcat: %s %s %s (abcd9876)\n", c, d, strcat(c, d));


    printf("\nstrtok:\n");

    char *s = (char*) calloc(11, sizeof(char));
    s[0] = ' ';
    s[1] = ' ';
    s[2] = ' ';
    s[3] = '9';
    s[4] = '8';
    s[5] = ' ';
    s[6] = 'c';
    s[7] = ' ';
    s[8] = 'e';
    s[9] = ' ';
    s[10] = '\0';
    printf("\"%s\"\n", s);

    char *word = strtok(s, " \t");
    while (word != NULL) {
        printf("word: %s\n", word);

        word = strtok(NULL, " \t");
    }


    return 0;
}
