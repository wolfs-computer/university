#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h> // for isprint()
#include "timer_opt_parser.h"
#include "status.h"



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

static Status opt_e(char *optarg, Opt_data *opts, int len) {
    int count = atoi(optarg);

    if (count < 1 || len == 0) return Invalid_arg;

    opts->element_count = count;

    return Success;
}

static Status opt_c(char *optarg, Opt_data *opts, int len) {
    int count = atoi(optarg);

    if (count < 1 || len == 0) return Invalid_arg;

    opts->count = count;

    return Success;
}


void parse_opts(int argc, char **argv, Opt_data *opts) {
    opterr = 0; // disable getopt error messages

    int len = 0;
    char c;

    Status opt_status;

    while ((c = getopt(argc, argv, "ha:f:d:e:c:")) != -1) {
        // printf("!\n");
        if (c != 'h' && optarg != NULL) len = strlen(optarg);
        // printf("opt %c %d\n", c, len);

        switch (c) {
            // help
            case 'h':
                printf(
                    "h -- display this help message\n\n"
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
                    "    [Example: -d u]\n\n"
                    "Generating:\n"
                    "e -- number of elements (any number > 0 and < 2147483647)\n"
                    "    Usage: -e NUMBER\n"
                    "    Default: 1\n"
                    "    [Example: -e 3]\n\n"
                    "c -- number of array (any number > 0 and < 2147483647)\n"
                    "    Usage: -c NUMBER\n"
                    "    Default: 1\n"
                    "    [Example: -c 3]\n\n"
                );

                return;

            // algorithm
            case 'a':
                opt_status = opt_a(optarg, opts, len);

                break;

            // field
            case 'f':
                opt_status = opt_f(optarg, opts, len);

                break;

            // direction
            case 'd':
                opt_status = opt_d(optarg, opts, len);

                break;

            // number of elements
            case 'e':
                opt_status = opt_e(optarg, opts, len);

                break;

            // number of arrays
            case 'c':
                opt_status = opt_c(optarg, opts, len);

                break;

            case '?':
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
        }
    }
}
