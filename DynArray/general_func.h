#ifndef GENERAL_FUNC_H
#define GENERAL_FUNC_H
#include <stddef.h> /* size_t */

/*
 * ndimalloc allocate a mutidimensional array and return 
 * a pointer to that array. THe array elements are "size"
 * bytes.
 * eg : 
 * 		ptr = ndimalloc(sizeof(long), 3, 4, 5, 6);
 * 		We get a pointer of void (*)[4][5][6]
 *
 * WARNING : 
 * 		The parameters after 'dim' must be 'int' type, or 
 * 		ramdon error may ocurr.
 * */
void * ndimalloc(size_t size, size_t dim, ...);

/*
 * free the memory allocated
 * */
void ndimfree(void * ptr, size_t dim, ...);

#endif /* GENERAL_FUNC_H */
