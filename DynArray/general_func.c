
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "general_func.h"

/* declaration */
static void * recursive_alloc(size_t size, size_t dim, va_list ap);
/*
 * ndimalloc allocate a mutidimensional array and return 
 * a pointer to that array. THe array elements are "size"
 * bytes.
 * */
void * ndimalloc(size_t size, size_t dim, ...)
{
	va_list ap;
	void * ret;

	va_start(ap,dim);
	ret = recursive_alloc(size, dim, ap);
	va_end(ap);
	
	return ret;
}

/*
 * Recursive implement of the multidimensional array
 * */
static void * recursive_alloc(size_t size, size_t dim, va_list ap)
{
	/* here TYPE we think is "int" */
	size_t firstdim = va_arg(ap, int);
	if (dim == 0)
		return NULL;
	if (dim == 1) {
		void * ptr = malloc(size * firstdim);
		return ptr;
	}
	void ** ret = malloc(sizeof(void *) * firstdim);
	va_list ap0;
	va_copy(ap0, ap);
	for (int i = 0; i < firstdim; i++) {
		va_copy(ap, ap0);
		ret[i] = recursive_alloc(size, dim-1, ap);
	}
	return ret;
}

