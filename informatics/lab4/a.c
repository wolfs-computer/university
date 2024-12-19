#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
// #include "status.h"




int sinsert(int *arr, int len, int elem) {

    for (int i = len - 1; i > 0; i--) {
        if (elem < arr[i - 1]) {
            arr[i] = arr[i - 1];
        } else {
            arr[i] = elem;
            return i;
            break;
        }
    }
    arr[0] = elem;

    return 0;
}


char *new_string(const char *input) {
    char *str;
    strcpy(str, input);
    int str_len = strlen(str);

    char *res = malloc((str_len + 1) * sizeof(char));
    int res_len = 0;


    int *word_lens = NULL;
    int *word_indexes = NULL;
    int word_count = 0;


    char *word = strtok(str, " \t");
    while (word != NULL) {
        // printf("w: %s", word);
        int word_len = strlen(word);
        res_len += word_len + 1;

        word_count++;
        word_lens = realloc(word_lens, word_count * sizeof(int));
        sinsert(word_lens, word_count, word_len);

        word_indexes = realloc(word_indexes, word_count * sizeof(int));

        word = strtok(NULL, " \t");
    }
    res_len--; // no space at the end

    // for (int i = 1; i < word_count; i++) {
    //     strncpy(, str + word_lens[i - 1] + 1, );
    // }



    return res;
}


int main() {

    char *input = readline("Input string: ");

    while (input != NULL) {

        printf("\"%s\"\n", input);

        char *output = new_string(input);
        printf("\"%s\"\n", output);

        free(input);
        free(output);

        input = readline("Input string: ");
    }


    return 0;
}
