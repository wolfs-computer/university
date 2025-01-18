#ifndef _OPT_PARSER_H_
#define _OPT_PARSER_H_


#include "status.h"


typedef enum _Opt {
    FLOW_STD = 0,
    FLOW_FILE_TXT = 1,
    FLOW_FILE_BIN = 2,

    ALGO_NO = 0,
    ALGO_COMB = 1,
    ALGO_HEAP = 2,
    ALGO_QSORT = 3,

    UP = 0,
    DOWN = 1,

} Opt;


typedef struct _Opt_data {
    Opt input;
    Opt output;

    char *input_filename;
    char *output_filename;

    Opt algorithm;
    int field;
    Opt direction;

} Opt_data;


void parse_opts(int argc, char **argv, Opt_data *opts);


#endif
