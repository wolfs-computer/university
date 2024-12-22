#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <time.h>



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


// void debug_pr(char **words, int *lens, int word_count) {
//     for (int i = 0; i < word_count; i++) {
//         // printf("-> ! %i\n", i);
//         printf("%s %i | %i/%i\n", words[i], lens[i], i, word_count - 1);
//     }
// }


char *new_string(const char *input) {
    int str_len = strlen(input);
    char *str = (char*) malloc((str_len + 1) * sizeof(char)); // null at the end
    strcpy(str, input);

    int *word_lens = NULL;
    char **word_indexes = NULL;
    int word_count = 0;


    char *word = strtok(str, " \t");
    while (word != NULL) {
        // printf("-> !\n");
        // printf("word: %s\n", word);

        int word_len = strlen(word);
        word_insert(&word_indexes, &word_lens, &word_count, word, word_len);

        word = strtok(NULL, " \t");
    }

    // debug_pr(word_indexes, word_lens, word_count);
    // printf("finished sorting %i\n", word_count);


    int res_len = 1;
    char *res = (char*) calloc(res_len, sizeof(char));

    for (int i = 0; i < word_count; i++) {
        res_len += word_lens[i] + 1;
        res = (char*) realloc(res, res_len * sizeof(char));
        strcat(res, word_indexes[i]);
        strcat(res, " ");
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

    char *input = readline("Input string: ");

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

        input = readline("Input string: ");
    }


    return 0;
}
