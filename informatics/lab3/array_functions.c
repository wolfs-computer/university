#include <stdio.h>
#include <stdlib.h>

#include "status.h"
#include "array_functions.h"



// Status array_init(int **arr) {
//
//     *arr = (int*) malloc(sizeof(int));
//
//     if (*arr == NULL) {
//         return Memory_fault;
//     }
//
//     return Success;
// }


void print_array(const int *arr, int len) {
    if (len == 0) {
        printf("Array is empty!\n");
        return;
    }

    for (int i = 0; i < len; i++) {
        printf("array[%d] = %d\n", i, arr[i]);
    }
}


Status array_insert_element(int **arr, int *len, int index, int value) {

    if (index < 0) return Invalid_index;

    (*len)++;

    if (index > *len) index = *len - 1;

    int *new_arr = (int*) realloc(*arr, *len * sizeof(int));
    if (new_arr == NULL) return Memory_fault;

    for (int i = *len - 2; i >= 0; i--) {
        if (i >= index) {
            new_arr[i + 1] = new_arr[i];
        } else {
            break;
        }
    }

    if (index < 0) index = 0;
    new_arr[index] = value;

    *arr = new_arr;

    return Success;
}


Status array_delete_element(int **arr, int *len, int index) {

    if (*len == 0) return Empty_array;
    if (index < 0 || index >= *len) return Invalid_index;
    // if (index > *len) index = *len;

    (*len)--;

    int last_digit = (*arr)[*len - 1];

    int *new_arr = (int*) realloc(*arr, *len * sizeof(int));
    if (new_arr == NULL) return Memory_fault;

    if (*len == 0) return Success;

    for (int i = index; i < *len - 1; i++) {
        new_arr[i] = new_arr[i + 1];
        if (i == *len - 2) new_arr[*len - 1] = last_digit;
    }

    *arr = new_arr;

    return Success;
}
