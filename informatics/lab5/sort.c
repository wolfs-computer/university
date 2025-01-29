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

void comb_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*)) {
    int gap = count;
    int swapped = 1;

    while (gap > 1 || swapped) {
        gap = gap * COMB_SHRINK;
        // if (gap < 1) gap = 1;

        swapped = 0;

        // gap comparison
        for (int i = 0; i + gap < count; i++) {
            // if (data[i] > data[i + gap]){
            if (comp(ptr + i, ptr + i + gap)) {

                // swap
                Data tmp = ((Data*) ptr)[i];
                ((Data*) ptr)[i] = ((Data*) ptr)[i + gap];
                ((Data*) ptr)[i + gap] = tmp;

                swapped = 1;
            }
        }
    }
}


int main() {

    Data a = {
        "0",
        "random random!",
        772
    };

    Data b = {
        "b",
        "S T R I N G",
        1
    };

    Data c = {
        "c",
        "G",
        11
    };

    Data l1[] = {a, c, b};
    int l1_len = 3;

    // printf("!\n");

    // qsort(l1, l1_len, sizeof(Data), comp_f3_down);
    comb_sort(l1, l1_len, sizeof(Data), comp_f3_up);

    // printf("!\n");

    // data_write_std(l1, l1_len);
    for (int i = 0; i < l1_len; i++) {
        printf("%d\n", i);
        printf("id -- %s\n", l1[i].id);
        printf("name -- %s\n", l1[i].name);
        printf("quantity -- %d\n", l1[i].quantity);
    }


    return 0;
}
