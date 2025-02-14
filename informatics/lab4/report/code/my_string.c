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

    char *token = str;
    str++;

    while (*str != '\0' && !check_delim(delim, *str)) str++;

    if (*str != '\0') {
        *str = '\0';
        str++;
    }

    return token;
}
