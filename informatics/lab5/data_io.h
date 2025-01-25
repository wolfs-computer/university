#ifndef _DATA_IO_H_
#define _DATA_IO_H_


#include "status.h"


#define ID_LEN 9

typedef struct _Data {
    char id[ID_LEN];
    char *name;
    unsigned int quantity;
} Data;


void data_write_std(const Data *data, const int data_len);
void data_read_std(Data **data, int *data_len);

void data_write_text(const char *filename, const Data *data, const int data_len);
Status data_read_text(const char *filename, Data **data, int *data_len);

Status data_write_bin(const char *filename, const Data *data, const int data_len);
Status data_read_bin(const char *filename, Data **data, int *data_len);


#endif
