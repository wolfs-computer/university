#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_io.h"



// qsort def -- UP



//################################################=-> Comparators <-=################################################//



//###=-> field 1 <-=###//

int comp_f1_up(const void *a, const void *b) {
    int r = strcmp(((Data*) a)->id, ((Data*) b)->id);

    if (r > 0) return 1; // a > b
    if (r < 0) return -1; // b > a

    return 0; // b == a
}

int comp_f1_down(const void *a, const void *b) {
    int r = strcmp(((Data*) a)->id, ((Data*) b)->id);

    if (r > 0) return -1; // a > b
    if (r < 0) return 1; // b > a

    return 0; // b == a
}



//###=-> field 2 <-=###//

int comp_f2_up(const void *a, const void *b) {
    int r = strcmp(((Data*) a)->name, ((Data*) b)->name);

    if (r > 0) return 1; // a > b
    if (r < 0) return -1; // b > a

    return 0; // b == a
}

int comp_f2_down(const void *a, const void *b) {
    int r = strcmp(((Data*) a)->name, ((Data*) b)->name);

    if (r > 0) return -1; // a > b
    if (r < 0) return 1; // b > a

    return 0; // b == a
}



//###=-> field 2 <-=###//

int comp_f3_up(const void *a, const void *b) {
    return ((Data*) a)->quantity - ((Data*) b)->quantity;
}

int comp_f3_down(const void *a, const void *b) {
    return ((Data*) b)->quantity - ((Data*) a)->quantity;
}



//################################################=-> Sort functions <-=################################################//



#define COMB_SHRINK 0.7

static void swap(void *a, void *b, size_t size) {
    void *tmp = malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}

void comb_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*)) {
    int gap = count;
    int swapped = 1;

    while (gap > 1 || swapped) {

        gap = gap * COMB_SHRINK;
        if (gap < 1) gap = 1;

        swapped = 0;

        // compare all elements within current gap
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



// int main() {
//
//     Data a = {
//         "0",
//         "random random!",
//         772
//     };
//
//     Data b = {
//         "b",
//         "S T R I N G",
//         1
//     };
//
//     Data c = {
//         "c",
//         "G",
//         11
//     };
//
//     Data l1[] = {a, c, b};
//     int l1_len = 3;
//
//
//     // qsort(l1, l1_len, sizeof(Data), comp_f3_up);
//     comb_sort(l1, l1_len, sizeof(Data), comp_f3_up);
//     // heap_sort(l1, l1_len, sizeof(Data), comp_f3_up);
//
//
//     for (int i = 0; i < l1_len; i++) {
//         printf("%d\n", i);
//         printf("id -- %s\n", l1[i].id);
//         printf("name -- %s\n", l1[i].name);
//         printf("quantity -- %d\n", l1[i].quantity);
//     }
//
//
//     return 0;
// }
