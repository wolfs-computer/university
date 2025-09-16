#include <stdio.h>
#include <stdlib.h>

#include "my_string.h"
#include "my_readline.h"



char *my_readline(const char *greet) {
    char buf[20] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;

    printf("%s", greet);

    do {
        n = scanf("%19[^\n]", buf);

        if (n < 0) {
            printf("\n");
            break;

        } else if (n > 0) {
            int chunk_len = my_strlen(buf);
            int str_len = len + chunk_len;
            res = (char*) realloc(res, str_len + 1);
            my_strcpy(res + len, buf);
            len = str_len;

        } else {
            scanf("%1[\n]", buf);
        }

    } while (n > 0);

    if (n < 0) {
        free(res);
        return NULL;
    }

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = (char*) calloc(1, sizeof(char));
    }

    return res;
}
