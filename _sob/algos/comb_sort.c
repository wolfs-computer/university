#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algos.h"



// INFO:
/*

Worst-case: O(n^2)
Best-case: O(n * log(n))

Avarege case: O(n^2 / 2^p), where p is a number of increments
Worst-case space complexity: O(1)

*/



static void swap(void *a, void *b, size_t size) {
    void *tmp = malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}



#define COMB_SHRINK 0.7

void comb_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*)) {
    int gap = count - 1;
    int swapped = 1;

    while (gap > 1 || swapped) {

        gap = gap * COMB_SHRINK;
        if (gap < 1) gap = 1;

        swapped = 0;

        // compare all elements with the distance between which is gap
        for (int i = 0; i < count - gap; i++) {

            // if (data[i] > data[i + gap]){
            if (comp((char*) ptr + i * size, (char*) ptr + (i + gap) * size) > 0) {
                // printf("%d %d %d\n", ((Data*) ptr)[i].quantity, ((Data*) ptr)[i + gap].quantity, comp((char*) ptr + i * size, (char*) ptr + (i + gap) * size));

                // swap
                // because char == 1 byte
                swap((char*) ptr + i * size, (char*) ptr + (i + gap) * size, size);

                swapped = 1;
            }
        }
    }
}
