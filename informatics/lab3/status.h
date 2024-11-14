#ifndef _STAUTS_H_
#define _STAUTS_H_


typedef enum _Status {
    Success = 0,
    Failure = -1,

    Memory_fault = 1,
    Invalid_index = 2,
    Empty_array = 3,

    Eof = 4,
    Invalid_input = 5,
    Incorrect_value = 6,

} Status;


#endif
