#ifndef _TIMER_OPT_PARSER_H_
#define _TIMER_OPT_PARSER_H_



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
    Opt algorithm;
    int field;
    Opt direction;

    int element_count;
    int count;

} Opt_data;


void parse_opts(int argc, char **argv, Opt_data *opts);



#endif
