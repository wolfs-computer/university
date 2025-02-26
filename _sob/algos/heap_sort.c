#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algos.h"



// INFO:
/*

Worst-case: O(n * log(n))
Best-case: O(n * log(n))

Avarege case: O(n * log(n))
Worst-case space complexity: O(1)

*/



static void swap(void *a, void *b, size_t size) {
    void *tmp = malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}



static void heapify(void *ptr, size_t count, size_t size, int i, int (*comp)(const void*, const void*)) {

    // root
    int largest = i;

    // left index
    int lt = 2 * i + 1; 

    // right index
    int rt = 2 * i + 2;


    // If left child is larger than largest
    // if (lt < count && ((char*) ptr + lt * size) > ((char*) ptr + largest * size)) {
    if (lt < count && comp((char*) ptr + lt * size, (char*) ptr + largest * size) > 0) {
        largest = lt;
    }

    // If right child is larger than largest
    // if (rt < count && ((char*) ptr + rt * size) > ((char*) ptr + largest * size)) {
    if (rt < count && comp((char*) ptr + rt * size, (char*) ptr + largest * size) > 0) {
        largest = rt;
    }


    // If largest is not root
    if (largest != i) {
        swap((char*) ptr + i * size, (char*) ptr + largest * size, size);

        // Recursively heapify the affected sub-tree
        heapify(ptr, count, size, largest, comp);
    }
}


void heap_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*)) {

    // build heap (rearrange array)
    for (int i = count / 2 - 1; i >= 0; i--) {
        heapify(ptr, count, size, i, comp);
    }

    // extract element one by one
    for (int i = count - 1; i > 0; i--) {
        // swap start and end
        swap((char*) ptr + 0 * size, (char*) ptr + i * size, size);

        heapify(ptr, i, size, 0, comp);
    }
}
