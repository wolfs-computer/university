#include <stdio.h>
#include <stdlib.h>

#include "status.h"
#include "array_functions.h"



Status array_init(int **arr) {

    *arr = (int*) malloc(sizeof(int));

    if (*arr == NULL) {
        return Memory_fault;
    }

    return Success;
}


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
    if (*len == 0) {
        (*arr)[0] = value;
        *len = 1;
        return Success;
    }

    (*len)++;
    int *new_arr = (int*) realloc(*arr, *len * sizeof(int));
    if (new_arr == NULL) return Memory_fault;

    for (int i = *len - 1; i >= 0; i--) {
        if (i >= index) {
            new_arr[i + 1] = new_arr[i];
        } else {
            break;
        }
    }

    new_arr[index] = value;

    arr = &new_arr;

    return Success;
}


Status array_delete_element(int **arr, int *len, int index) {

    if (*len == 0) return Empty_array;
    if (index < 0 || index >= *len) return Invalid_index;
    if (index > *len) index = *len;

    (*len)--;
    int *new_arr = (int*) realloc(*arr, *len * sizeof(int));
    if (new_arr == NULL) return Memory_fault;

    for (int i = index; i < *len; i++) {
        if (i >= index) {
            new_arr[i] = (*arr)[i + 1];
        } else {
            break;
        }
    }

    arr = &new_arr;

    return Success;
}
