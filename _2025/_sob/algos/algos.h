#ifndef _ALGOS_H_
#define _ALGOS_H_


#include <stddef.h>



void bubble_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*));
void comb_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*));
void heap_sort(void *ptr, size_t count, size_t size, int (*comp)(const void*, const void*));



#endif
