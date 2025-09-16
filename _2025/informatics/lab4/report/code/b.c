#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "my_string.h"
#include "my_readline.h"



void word_insert(char ***words, int **lens, int *word_count, char *word, int len) {

    (*word_count)++;
    *lens = (int*) realloc(*lens, *word_count * sizeof(int));
    *words = (char**) realloc(*words, *word_count * sizeof(char*));

    for (int i = *word_count - 2; i >= 0; i--) {
        if ((*lens)[i] <= len) {
            (*lens)[i + 1] = len;
            (*words)[i + 1] = word;
            return;
        } else {
            (*lens)[i + 1] = (*lens)[i];
            (*words)[i + 1] = (*words)[i];
        }
    }

    (*lens)[0] = len;
    (*words)[0] = word;
}


char *new_string(const char *input) {
    int str_len = my_strlen(input);
    char *str = (char*) malloc((str_len + 1) * sizeof(char));
    my_strcpy(str, input);

    int *word_lens = NULL;
    char **word_indexes = NULL;
    int word_count = 0;

    char *word = my_strtok(str, " \t");
    while (word != NULL) {

        int word_len = my_strlen(word);
        word_insert(&word_indexes, &word_lens, &word_count, word, word_len);

        word = my_strtok(NULL, " \t");
    }

    int res_len = 1;
    char *res = (char*) calloc(res_len, sizeof(char));

    for (int i = 0; i < word_count; i++) {
        res_len += word_lens[i] + 1;
        res = (char*) realloc(res, res_len * sizeof(char));
        my_strcat(res, word_indexes[i]);
        my_strcat(res, " ");
    }

    if (res_len > 1) {
        res_len--;
        res = (char*) realloc(res, res_len * sizeof(char));
        res[res_len - 1] = '\0';
    }

    free(str);
    free(word_lens);
    free(word_indexes);
    free(word);

    return res;
}


int main() {

    char *input = my_readline("Input string: ");

    while (input != NULL) {

        printf("\"%s\"\n", input);

        clock_t start = clock();
        char *output = new_string(input);
        clock_t stop = clock();
        float time = (float) (stop - start) / CLOCKS_PER_SEC;

        printf("time: %f\n", time);
        printf("\"%s\"\n\n", output);

        free(input);
        free(output);

        input = my_readline("Input string: ");
    }

    return 0;
}
