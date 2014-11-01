#ifndef GENERAL_FUNC_H
#define GENERAL_FUNC_H
#include <stddef.h> /* size_t */

/*
 * ndimalloc allocate a mutidimensional array and return 
 * a pointer to that array. THe array elements are "size"
 * bytes.
 * */
void * ndimalloc(size_t size, size_t dim, ...);

#endif /* GENERAL_FUNC_H */
