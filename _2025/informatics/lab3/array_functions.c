#include <stdio.h>
#include <stdlib.h>

#include "status.h"
#include "array_functions.h"



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

    if (index > *len) index = *len;
    (*len)++;

    *arr = (int*) realloc(*arr, *len * sizeof(int));
    if (*arr == NULL) return Memory_fault;

    for (int i = *len - 2; i >= 0; i--) {
        if (i >= index) {
            (*arr)[i + 1] = (*arr)[i];
        } else {
            break;
        }
    }

    (*arr)[index] = value;

    return Success;
}


Status array_delete_element(int **arr, int *len, int index) {

    if (*len == 0) return Empty_array;
    if (index < 0 || index >= *len) return Invalid_index;

    if (*len == 1) {
        free(*arr);
        *arr = NULL;
        *len = 0;
        return Success;
    }

    for (int i = index; i < *len - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    (*len)--;

    *arr = (int*) realloc(*arr, *len * sizeof(int));
    if (*arr == NULL) return Memory_fault;

    return Success;
}
