#ifndef GENERAL_FUNC_H
#define GENERAL_FUNC_H
#include <stddef.h> /* size_t */

/*
 * ndimalloc allocate a 'dim' dimensional array and return 
 * a pointer to that array. THe array elements are "size"
 * bytes.
 * eg : 
 * 		ptr = ndimalloc(sizeof(long), 3, "d", 4, 5, 6);
 * 		We get a pointer of void (*)[4][5][6]
 * 		the string "d" means the format of '4', '5', '6'.
 * 		Now 'format' supports for : 
 * 			"d" ------ 	int
 * 			"ld" -----	long int
 * 			"lld" ----	long long int
 * 			"u" ------ 	unsigned
 * 			"lu" ----- 	long unsigned
 * 			"llu" ---- 	long long unsigned
 * */
void * ndimalloc(size_t size, size_t dim, char * format, ...);

/*
 * free the memory allocated. The meaning of 'dim' nad 'format'
 * is the same as ndimalloc
 * */
void ndimfree(void * ptr, size_t dim, char * format, ...);

#endif /* GENERAL_FUNC_H */
