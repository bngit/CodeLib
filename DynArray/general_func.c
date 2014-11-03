
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "general_func.h"

/*
 * Recursive implement of the multidimensional array
 * */
static void * recursive_alloc(size_t size, size_t dim, va_list ap)
{
	/* here TYPE we think is "int" */
	int firstdim = va_arg(ap, int);
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

/*
 * Recursive implement of the free function
 * */
static void recursive_free(void * ptr, int dim, va_list ap)
{
	if (dim == 0)
		return;
	if (dim == 1) {
		free(ptr);
		return;
	}
	int firstdim = va_arg(ap, int);
	va_list ap0;
	va_copy(ap0, ap);
	void ** pcon = ptr;
	for (int i = 0; i < firstdim; i++) {
		va_copy(ap, ap0);
		recursive_free(pcon[i], dim-1, ap);
	}
	free(ptr);
}

/*
 * free the memory allocated
 * */
void ndimfree(void * ptr, size_t dim, ...)
{
	va_list ap;
	va_start(ap, dim);
	recursive_free(ptr, dim, ap);
	va_end(ap);
}
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

