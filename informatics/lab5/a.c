#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h> // for isprint()
#include "status.h"



typedef struct _Data {
    char str[8];
    char *name;
    unsigned int quantity;
} Data;


void write_data_text(char *filename, Data *data, int data_len) {
    FILE *f = fopen(filename, "w");

    fprintf(f, "%d\n", data_len);
    for (int i = 0; i < data_len; i++) {
        fprintf(f, "%s\n", data[i].str);
        fprintf(f, "%s\n", data[i].name);
        fprintf(f, "%d\n", data[i].quantity);
    }

    fclose(f);
}

void read_data_text(char *filename, Data **data, int *data_len) {
    FILE *f = fopen(filename, "r");

    fscanf(f, "%d\n", data_len);

    for (int i = 0; i < *data_len; i++) {
        // printf("!!\n");
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));
        // if (!data) exit(1);

        // always 8
        fscanf(f, "%s\n", (*data)[i].str);
        // printf("%s\n", (*data)[i].str);

        (*data)[i].name = NULL;
        int l = 1;
        char c = fgetc(f);
        while (c != '\n') {
            (*data)[i].name = (char*) realloc((*data)[i].name, (l + 1) * sizeof(char));
            (*data)[i].name[l - 1] = c;
            c = fgetc(f);
            l++;
        }
        (*data)[i].name[l - 1] = '\0';
        // printf("%s\n", (*data)[i].name);

        fscanf(f, "%d\n", &((*data)[i].quantity));
        // printf("%d\n", (*data)[i].quantity);
    }

    fclose(f);
}

void write_data_bin(char *filename, Data *data, int data_len) {
    FILE *f = fopen(filename, "w+b");

    fwrite(&data_len, sizeof(data_len), 1, f);
    for (int i = 0; i < data_len; i++) {
        // always 8
        fwrite(data[i].str, sizeof(char), 8, f);

        // size of next object
        int l = strlen(data[i].name) + 1;
        fwrite(&l, sizeof(l), 1, f);
        fwrite(data[i].name, sizeof(char), l, f);

        fwrite(&(data[i].quantity), sizeof(unsigned int), 1, f);
    }

    fclose(f);
}

void read_data_bin(char *filename, Data **data, int *data_len) {
    FILE *f = fopen(filename, "r+b");

    fread(data_len, sizeof(*data_len), 1, f);

    for (int i = 0; i < *data_len; i++) {
        // printf("!!\n");
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));
        // if (!data) exit(1);

        // always 8
        fread((*data)[i].str, sizeof(char), 8, f);
        // printf("%s\n", (*data)[i].str);

        // size of next object
        // int l = strlen(data[i].name) + 1;
        int l;
        fread(&l, sizeof(l), 1, f);
        // printf("%d\n", l);
        (*data)[i].name = (char*) calloc(l, sizeof(char));
        fread((*data)[i].name, sizeof(char), l, f);
        // printf("%s\n", (*data)[i].name);

        fread(&((*data)[i].quantity), sizeof(unsigned int), 1, f);
        // printf("%d\n", (*data)[i].quantity);
    }

    fclose(f);
}



int main(int argc, char **argv) {
    /*
    h -- display this help message

    // i -- input method (std, txt, bin)
    // o -- output method (std, txt, bin)

    a -- algorithm (1, 2, 3)
    f -- fields of the structure (1, 2, 3) plain string (32)
    d -- sort direction (-, +)
    */


    Opt input = FLOW_STD;
    Opt output = FLOW_STD;
    Opt algorithm = ALGO_COMB;

    char *input_filename = NULL;
    char *output_filename = NULL;

    int len = 0;

    char c;
    while ((c = getopt(argc, argv, "hi:o:a:f:d:")) != -1) {
        printf("!\n");

        switch (c) {
            case 'h':
                printf(
                   "h -- display this help message\n\n"
                   "Input/Output:\n"
                   "i -- input method (std, txt, bin)\n"
                   "    Usage: -i METHOD,FILENAME\n"
                   "    Default: std\n"
                   "    [Example: -i txt,input.txt]\n\n"
                   "o -- output method (std, txt, bin)\n"
                   "    Usage: -o METHOD,FILENAME\n"
                   "    Default: std\n"
                   "    [Example: -o txt,output.txt]\n\n"
                   "Sorting:\n"
                   "a -- algorithm (0, 1, 2, 3)\n"
                   "    0 -> no sort\n"
                   "    1 -> comb sort\n"
                   "    2 -> heap sort\n"
                   "    3 -> qsort\n"
                   "    Usage: -a ALGORITHM\n"
                   "    Default: 0\n"
                   "    [Example: -a 2]\n\n"
                   "f -- fields of the structure (1, 2, 3)\n"
                   "    Can be combined like 23, 12.\n"
                   "    Usage: -f [FIELD1][FIELD2][FIELD3]\n"
                   "    Default: 1\n"
                   "    [Example: -f 23]\n\n"
                   "d -- sort direction (-, +)\n"
                   "    Usage: -d DIRECTION\n"
                   "    Default: +\n"
                   "    [Example: -d -]\n"
                );
                return 0;
                break;

            case 'i':
                len = strlen(optarg);

                if (len < 3) {
                    fprintf(stderr, "[Error] Invalid argument for -i.\n");
                    break;
                }

                if (!strncmp(optarg, "std", 3)) break;
                
                if (len < 5) {
                    fprintf(stderr, "[Error] Invalid argument for -i.\n");
                    break;
                }

                if (!strncmp(optarg, "txt", 3)) input = FLOW_FILE_TXT;
                else if (!strncmp(optarg, "bin", 3)) input = FLOW_FILE_BIN;
                else {
                    fprintf(stderr, "[Error] Invalid argument for -i.\n");
                    break;
                }

                input_filename = (char*) calloc(len - 4, sizeof(char));
                strcat(input_filename, optarg + 4);

                break;

            case 'o':
                len = strlen(optarg);

                if (len < 3) {
                    fprintf(stderr, "[Error] Invalid argument for -o.\n");
                    break;
                }

                if (!strncmp(optarg, "std", 3)) break;
                
                if (len < 5) {
                    fprintf(stderr, "[Error] Invalid argument for -o.\n");
                    break;
                }

                if (!strncmp(optarg, "txt", 3)) output = FLOW_FILE_TXT;
                else if (!strncmp(optarg, "bin", 3)) output = FLOW_FILE_BIN;
                else {
                    fprintf(stderr, "[Error] Invalid argument for -o.\n");
                    break;
                }

                output_filename = (char*) calloc(len - 4, sizeof(char));
                strcat(output_filename, optarg + 4);

                break;

            case '?':
                // printf("opt ? -- %s\n", optarg);
                if (strchr("ioafd", optopt) != NULL) {
                    // fprintf(stderr, "[Error] Option %c requires an argument.\n", optopt);
                    // it do it
                } else if (isprint(optopt)) {
                    fprintf(stderr, "[Error] Unknown option %c.\n", optopt);
                } else {
                    fprintf(stderr, "[Error] Unknown option character \\x%x.\n", optopt);
                }
                break;
        }
    }

    printf("input source -- %d\n", input);
    printf("input filename -- %s\n\n", input_filename);

    printf("output source -- %d\n", output);
    printf("output filename -- %s\n", output_filename);



    return 0;






    Data a = {
        "1234567",
        "random string",
        9
    };

    Data b = {
        "0000000",
        "random string and more data!!!",
        11
    };

    Data list[] = {a, b};


    // write_data_text("1test", list, 2);
    //
    // int data_len = 0;
    // Data *l = NULL;
    // read_data_text("1test", &l, &data_len);
    //
    // for (int i = 0; i < data_len; i++) {
    //     printf("%s\n", l[i].str);
    //     printf("%s\n", l[i].name);
    //     printf("%d\n", l[i].quantity);
    //     free(l[i].name);
    // }
    // free(l);


    // write_data_bin("2test", list, 2);
    //
    // int data_len = 0;
    // Data *l = NULL;
    // read_data_bin("2test", &l, &data_len);
    //
    // for (int i = 0; i < data_len; i++) {
    //     printf("%s\n", l[i].str);
    //     printf("%s\n", l[i].name);
    //     printf("%d\n", l[i].quantity);
    //     free(l[i].name);
    // }
    // free(l);



    return 0;
}
