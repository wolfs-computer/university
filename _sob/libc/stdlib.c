// #include <stdlib.h>
#include <stdio.h>



/* ###############################################=-> dynamic memory allocation <-=############################################### */



/*
Allocates size bytes of uninitialized storage.

If allocation succeeds, returns a pointer that is suitably aligned for any object type with fundamental alignment.

If size is zero, the behavior of malloc is implementation-defined.
For example, a null pointer may be returned.
Alternatively, a non-null pointer may be returned;
but such a pointer should not be dereferenced, and should be passed to free to avoid memory leaks. 
*/
void *malloc(size_t size);



/*
Allocates memory for an array of num objects of size and initializes all bytes in the allocated storage to zero.

If allocation succeeds, returns a pointer to the lowest (first) byte in the allocated memory block that is suitably aligned for any object type with fundamental alignment.

If size is zero, the behavior is implementation defined
(null pointer may be returned, or some non-null pointer may be returned that may not be used to access storage). 
*/
void *calloc(size_t num, size_t size);



/*
Reallocates the given area of memory.


If ptr is not NULL, it must be previously allocated by malloc, calloc or realloc and not yet freed with a call to free or realloc.
Otherwise, the results are undefined.

The reallocation is done by either:
    a) expanding or contracting the existing area pointed to by ptr, if possible.
    The contents of the area remain unchanged up to the lesser of the new and old sizes.
    If the area is expanded, the contents of the new part of the array are undefined.

    b) allocating a new memory block of size new_size bytes,
    copying memory area with size equal the lesser of the new and the old sizes,
    and freeing the old block.

If there is not enough memory, the old memory block is not freed and null pointer is returned.

If ptr is NULL, the behavior is the same as calling malloc(new_size). 


if new_size is zero, the behavior is undefined. 
*/
void *realloc(void *ptr, size_t new_size);



/*
Deallocates the space previously allocated by malloc(), calloc(), aligned_alloc(),(since C11) or realloc().


If ptr is a null pointer, the function does nothing.

The behavior is undefined if the value of ptr does not equal a value returned earlier by malloc(), calloc(), realloc(), or aligned_alloc()(since C11).

The behavior is undefined if the memory area referred to by ptr has already been deallocated, that is, free(), free_sized(), free_aligned_sized()(since C23), or realloc() has already been called with ptr as the argument and no calls to malloc(), calloc(), realloc(), or aligned_alloc()(since C11) resulted in a pointer equal to ptr afterwards.

The behavior is undefined if after free() returns, an access is made through the pointer ptr (unless another allocation function happened to result in a pointer value equal to ptr). 
*/
void free(void *ptr);
