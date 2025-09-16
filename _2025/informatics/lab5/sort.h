#ifndef _SORT_H_
#define _SORT_H_


#include <stdio.h>



int comp_f1_up(const void *a, const void *b);
int comp_f1_down(const void *a, const void *b);
int comp_f2_up(const void *a, const void *b);
int comp_f2_down(const void *a, const void *b);
int comp_f3_up(const void *a, const void *b);
int comp_f3_down(const void *a, const void *b);

void comb_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*));
void heap_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*));



#endif
