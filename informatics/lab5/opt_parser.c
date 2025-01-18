#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h> // for isprint()
#include "status.h"
#include "opt_parser.h"



void parse_opts(int argc, char **argv, Opt_data *opts) {

    char c;
    while ((c = getopt(argc, argv, "hi:o:a:f:d:")) != -1) {
        // printf("!\n");
        int len = strlen(optarg);

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
                    "    Usage: -f FIELD\n"
                    "    Default: 1\n"
                    "    [Example: -f 3]\n\n"
                    "d -- sort direction (d, u)\n"
                    "    d(own) and u(p)\n"
                    "    Usage: -d DIRECTION\n"
                    "    Default: +\n"
                    "    [Example: -d u]\n"
                );

                return;

            // input
            case 'i':
                if (len < 3) {
                    fprintf(stderr, "[Error] Invalid argument for -i.\n");
                    break;
                }

                if (!strncmp(optarg, "std", 3)) break;
                
                if (len < 5) {
                    fprintf(stderr, "[Error] Invalid argument for -i.\n");
                    break;
                }

                if (!strncmp(optarg, "txt", 3)) opts->input = FLOW_FILE_TXT;
                else if (!strncmp(optarg, "bin", 3)) opts->input = FLOW_FILE_BIN;
                else {
                    fprintf(stderr, "[Error] Invalid argument for -i.\n");
                    break;
                }

                opts->input_filename = (char*) calloc(len - 4, sizeof(char));
                strcat(opts->input_filename, optarg + 4);

                break;

            // output
            case 'o':

                if (len < 3) {
                    fprintf(stderr, "[Error] Invalid argument for -o.\n");
                    break;
                }

                if (!strncmp(optarg, "std", 3)) break;
                
                if (len < 5) {
                    fprintf(stderr, "[Error] Invalid argument for -o.\n");
                    break;
                }

                if (!strncmp(optarg, "txt", 3)) opts->output = FLOW_FILE_TXT;
                else if (!strncmp(optarg, "bin", 3)) opts->output = FLOW_FILE_BIN;
                else {
                    fprintf(stderr, "[Error] Invalid argument for -o.\n");
                    break;
                }

                opts->output_filename = (char*) calloc(len - 4, sizeof(char));
                strcat(opts->output_filename, optarg + 4);

                break;

            // algorithm
            case 'a':
                if (len != 1) {
                    fprintf(stderr, "[Error] Invalid argument for -a.\n");
                    break;
                }

                if (optarg[0] == '1') opts->algorithm = ALGO_COMB;
                else if (optarg[0] == '2') opts->algorithm = ALGO_HEAP;
                else if (optarg[0] == '3') opts->algorithm = ALGO_QSORT;

                break;

            // field
            case 'f':
                if (len != 1) {
                    fprintf(stderr, "[Error] Invalid argument for -f.\n");
                    break;
                }

                if (optarg[0] == '2') opts->field = 1;
                else if (optarg[0] == '3') opts->field = 2;

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
}
