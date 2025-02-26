#include <stdio.h>
// #include <stdlib.h>
#include "algos.h"



int comp_int(const void *a, const void *b) {
    return *((int*) a) - *((int*) b);
}




int main() {

    int l1[] = {1, 4, 56, -3, 45, 0};
    int len_l1 = sizeof(l1) / sizeof(l1[0]);


    for (int i = 0; i < len_l1; i++) {
        printf("%i ", l1[i]);
    }
    printf("\n");


    // qsort(l1, len_l1, sizeof(int), comp_int);
    // bubble_sort(l1, len_l1, sizeof(int), comp_int);
    // comb_sort(l1, len_l1, sizeof(int), comp_int);
    heap_sort(l1, len_l1, sizeof(int), comp_int);


    for (int i = 0; i < len_l1; i++) {
        printf("%i ", l1[i]);
    }
    printf("\n");

    



    return 0;
}
