#ifndef _ARRAY_FUNCTIONS_H_
#define _ARRAY_FUNCTIONS_H_

#include "status.h"



// Status array_init(int **arr);
void print_array(const int *arr, int len);

Status array_insert_element(int **arr, int *len, int index, int value);
Status array_delete_element(int **arr, int *len, int index);



#endif
