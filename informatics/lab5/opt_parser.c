#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h> // for isprint()
#include "opt_parser.h"
#include "status.h"



static int does_file_exists(char *filename) {
    FILE *f;
    if ((f = fopen(filename, "r"))) {
        fclose(f);
        return 1;
    }
    return 0;
}

static Status opt_i(char *optarg, Opt_data *opts, int len) {
    if (len < 3) return Invalid_arg;

    if (!strncmp(optarg, "std", 3)) return Success;

    if (len < 5) return Invalid_arg;

    if (!does_file_exists(optarg + 4)) return File_open_fault;

    opts->input_filename = (char*) calloc(len - 4, sizeof(char));
    strcat(opts->input_filename, optarg + 4);

    if (!strncmp(optarg, "txt", 3)) opts->input = FLOW_FILE_TXT;
    else if (!strncmp(optarg, "bin", 3)) opts->input = FLOW_FILE_BIN;
    else return Invalid_arg;

    return Success;
}

static Status opt_o(char *optarg, Opt_data *opts, int len) {
    if (len < 3) return Invalid_arg;

    if (!strncmp(optarg, "std", 3)) return Success;

    if (len < 5) return Invalid_arg;

    if (!strncmp(optarg, "txt", 3)) opts->output = FLOW_FILE_TXT;
    else if (!strncmp(optarg, "bin", 3)) opts->output = FLOW_FILE_BIN;
    else return Invalid_arg;

    opts->output_filename = (char*) calloc(len - 4, sizeof(char));
    strcat(opts->output_filename, optarg + 4);

    return Success;
}

static Status opt_a(char *optarg, Opt_data *opts, int len) {
    if (len != 1) return Invalid_arg;

    if (optarg[0] == '1') opts->algorithm = ALGO_COMB;
    else if (optarg[0] == '2') opts->algorithm = ALGO_HEAP;
    else if (optarg[0] == '3') opts->algorithm = ALGO_QSORT;
    else return Invalid_arg;

    return Success;
}

static Status opt_f(char *optarg, Opt_data *opts, int len) {
    if (len != 1) return Invalid_arg;

    if (optarg[0] == '1') opts->field = 0;
    else if (optarg[0] == '2') opts->field = 1;
    else if (optarg[0] == '3') opts->field = 2;
    else return Invalid_arg;

    return Success;
}

static Status opt_d(char *optarg, Opt_data *opts, int len) {
    if (len != 1) return Invalid_arg;

    if (optarg[0] == 'u') opts->direction = UP;
    else if (optarg[0] == 'd') opts->direction = DOWN;
    else return Invalid_arg;

    return Success;
}


void parse_opts(int argc, char **argv, Opt_data *opts) {
    opterr = 0; // disable getopt error messages

    int len = 0;
    char c;

    Status opt_status;

    while ((c = getopt(argc, argv, "hi:o:a:f:d:")) != -1) {
        // printf("!\n");
        if (c != 'h' && optarg != NULL) len = strlen(optarg);
        // printf("opt %c %d\n", c, len);

        switch (c) {
            // help
            case 'h':
                printf(
                    "h -- display this help message\n\n"
                    "Input/Output:\n"
                    "i -- input method (std, txt, bin)\n"
                    "    std -> standard input\n"
                    "    txt -> text file\n"
                    "    bin -> binary file\n"
                    "    Usage: -i METHOD,FILENAME\n"
                    "    Default: std\n"
                    "    [Example: -i txt,input.txt]\n\n"
                    "o -- output method (std, txt, bin)\n"
                    "    std -> standard output\n"
                    "    txt -> text file\n"
                    "    bin -> binary file\n"
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
                    "f -- field of the structure (1, 2, 3)\n"
                    "    Usage: -f FIELD\n"
                    "    Default: 1\n"
                    "    [Example: -f 3]\n\n"
                    "d -- sort direction (d, u)\n"
                    "    d(own) and u(p)\n"
                    "    Usage: -d DIRECTION\n"
                    "    Default: u\n"
                    "    [Example: -d u]\n"
                );

                return;

            // input
            case 'i':
                opt_status = opt_i(optarg, opts, len);

                break;

            // output
            case 'o':
                opt_status = opt_o(optarg, opts, len);

                break;

            // algorithm
            case 'a':
                opt_status = opt_a(optarg, opts, len);

                break;

            // field
            case 'f':
                opt_status = opt_f(optarg, opts, len);

                break;

            // field
            case 'd':
                opt_status = opt_d(optarg, opts, len);

                break;

            case '?':
                // printf("!!\n");
                // printf("opt ? -- %s\n", optarg);
                if (strchr("ioafd", optopt) != NULL) {
                    fprintf(stderr, "[Error] Option %c requires an argument.\n", optopt);
                } else if (isprint(optopt)) {
                    fprintf(stderr, "[Error] Unknown option %c.\n", optopt);
                } else {
                    fprintf(stderr, "[Error] Unknown option character \\x%x.\n", optopt);
                }

                break;
        }

        if (opt_status == Invalid_arg) {
            fprintf(stderr, "[Error] Invalid argument for -%c.\n", c);
        } else if (opt_status == File_open_fault) {
            fprintf(stderr, "[Error] Error when opening input file.\n");
        }
    }
}
