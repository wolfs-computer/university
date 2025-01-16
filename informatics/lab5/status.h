#ifndef _STATUS_H_
#define _STATUS_H_


// typedef enum _Status {
//     Success = 0,
//     Failure = -1,
//
//     Memory_fault = 1,
//     Invalid_index = 2,
//     Empty_array = 3,
//
//     Eof = 4,
//     Invalid_input = 5,
//     Incorrect_value = 6,
//
// } Status;

typedef enum _Opt {
    FLOW_STD = 0,
    FLOW_FILE_TXT = 1,
    FLOW_FILE_BIN = 2,

    ALGO_NO = 0,
    ALGO_COMB = 1,
    ALGO_HEAP = 2,
    ALGO_QSORT = 3,

} Opt;


#endif
