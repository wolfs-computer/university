#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"



size_t strlen (const char *s) {
    int res = 0;

    while (*s) {
        ++s;
        ++res;
    }

    return res;
}


char *strcpy (char *dest, const char *src) {
    int i = 0;
    
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }

    return dest;
}


char *strcat (char *dest, const char *src) {
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


char *strtok (char *s, const char *delim) {

    static char* str;
    static int s_pos = 0;

    if (s != NULL) {
        str = (char*) calloc(strlen(s) + 1, sizeof(char));
        strcpy(str, s);
    }

    // if (!s || !delim || str[s_pos] == '\0') return NULL;
    if (!delim || str[s_pos] == '\0') {
        free(str);
        return NULL;
    }


    // printf("%c %i %s\n", str[s_pos], str[s_pos] == '\0', str);
    while (str[s_pos] != '\0' && check_delim(delim, str[s_pos])) s_pos++;
    // printf("%c %i %s\n", str[s_pos], str[s_pos] == '\0', str);
    if (str[s_pos] == '\0') {
        free(str);
        return NULL;
    }
    // s_pos++;
    // return NULL;

    char *token = str + s_pos;

    printf("%c %i %s\n", str[s_pos], str[s_pos] == '\0', str);
    while (str[s_pos] != '\0' && !check_delim(delim, str[s_pos])) s_pos++;
    if (str[s_pos] != '\0') {
        str[s_pos] = '\0';
        s_pos++;
        return token;
    } else {
        free(str);
        return NULL;
    }

}


// DEBUG
int main () {

    char a[] = "1234";
    printf("strlen: %i\n", (int) strlen(a));

    char b[] = "0000";
    printf("strcpy: %s %s\n", b, strcpy(b, a));

    char *c = (char*) malloc(9 * sizeof(char));
    c[0] = 'a';
    c[1] = 'b';
    c[2] = 'c';
    c[3] = 'd';
    char d[] = "9876";
    printf("strcat: %s %s %s\n", c, d, strcat(c, d));


    printf("\nstrtok:\n");
    char *s = (char*) calloc(5, sizeof(char));
    s[0] = 'a';
    s[1] = ' ';
    s[2] = 'c';
    s[3] = 'd';
    s[4] = '\0';
    char *word = strtok(s, " \t");
    // printf("word: %s\n", word);
    while (word != NULL) {
        // printf("-> !\n");
        printf("word: %s\n", word);

        word = strtok(NULL, " \t");
    }
    // printf("df\n");


    return 0;
}
