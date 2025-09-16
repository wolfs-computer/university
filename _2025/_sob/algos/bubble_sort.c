#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algos.h"



// INFO:
/*

Worst-case: O(n^2)
Best-case: O(n)

Avarege case: O(n^2)
Worst-case space complexity: O(1)

*/



static void swap(void *a, void *b, size_t size) {
    void *tmp = malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}



void bubble_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*)) {

    for (int i = 0; i < count - 1; i++) {
        int swapped = 0;

        for (int g = 0; g < count - i - 1; g++) {
            if (comp((char*) ptr + g * size, (char*) ptr + (g + 1) * size) > 0) {
                swap((char*) ptr + g * size, (char*) ptr + (g + 1) * size, size);
                swapped = 1;
            }
        }

        // if no elements were swapped
        if (swapped == 0) break;
    }
}
