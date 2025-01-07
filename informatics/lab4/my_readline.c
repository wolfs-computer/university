#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUF_SIZE 81


char *get_char(const char *greet) {
    char buf[BUF_SIZE] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;

    printf("%s", greet);

    do {
        n = scanf("%80[^\n]", buf);

        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}



// DEBUG
int main() {

    while (1) {
        char *input = get_char("Input string: ");
        printf("%s\n", input);
    }


    return 0;
}
