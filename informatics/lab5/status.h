#ifndef _STATUS_H_
#define _STATUS_H_


typedef enum _Status {
    Success = 0,
    Failure = -1,

    Memory_fault,

    // opts parsing
    Invalid_arg,
    File_open_fault,

} Status;


#endif
