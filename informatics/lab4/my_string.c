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

    while (*dest) ++dest;

    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
    }

    return dest;
}


int check_delim(const char *delim, char c) {
    while (*delim != '\0') {
        if (*delim == c) return 1;
        delim++;
    }
    return 0;
}


char *strtok (char *s, const char *delim) {

    static int s_pos = 0;

    if (!s || !delim || s[s_pos] == '\0') return NULL;


    if (s != NULL) {
        int i = 0;

        while (s[i] != '\0' || !check_delim(delim, s[i])) i++;
        if (s[i] == '\0') return NULL;

        char *token = s + i;

        while (s[i] != '\0' || check_delim(delim, s[i])) i++;

        s_pos = i;
        if (s[i] != '\0') {
            s[i] = '\0';
            s_pos++;
        }
        return token;
    }




    return NULL;
}
