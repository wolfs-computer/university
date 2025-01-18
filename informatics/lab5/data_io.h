#ifndef _DATA_IO_H_
#define _DATA_IO_H_


typedef struct _Data {
    char id[9];
    char *name;
    unsigned int quantity;
} Data;


void data_write_std(Data *data, int data_len);
void data_read_std(Data **data, int *data_len);

void data_write_text(char *filename, Data *data, int data_len);
void data_read_text(char *filename, Data **data, int *data_len);

void data_write_bin(char *filename, Data *data, int data_len);
void data_read_bin(char *filename, Data **data, int *data_len);


#endif
