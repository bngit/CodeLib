
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "general_func.h"

/*
 * return proper data according to the 'format' string
 * */
size_t format_arg(va_list ap, char * format)
{
	if (strcmp(format, "d") == 0) return va_arg(ap, int);
	if (strcmp(format, "ld") == 0) return va_arg(ap, long);
	if (strcmp(format, "lld") == 0) return va_arg(ap, long long);
	if (strcmp(format, "u") == 0) return va_arg(ap, unsigned);
	if (strcmp(format, "lu") == 0) return va_arg(ap, long unsigned);
	if (strcmp(format, "llu") == 0) return va_arg(ap, long long unsigned);
	fprintf(stderr, "ndimalloc/ndimfree: can't accept this format!\n");
	exit(EXIT_FAILURE);
}

/*
 * Recursive implement of the multidimensional array
 * */
static void * recursive_alloc(size_t size, size_t dim, 
		char * format, va_list ap)
{
	/* here TYPE we think is "int" */
	size_t firstdim = format_arg(ap, format);
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
		ret[i] = recursive_alloc(size, dim-1, format, ap);
	}
	return ret;
}

/*
 * Recursive implement of the free function
 * */
static void recursive_free(void * ptr, int dim, char * format, va_list ap)
{
	if (dim == 0)
		return;
	if (dim == 1) {
		free(ptr);
		return;
	}
	int firstdim = format_arg(ap, format);
	va_list ap0;
	va_copy(ap0, ap);
	void ** pcon = ptr;
	for (int i = 0; i < firstdim; i++) {
		va_copy(ap, ap0);
		recursive_free(pcon[i], dim-1, format, ap);
	}
	free(ptr);
}

/*
 * free the memory allocated
 * */
void ndimfree(void * ptr, size_t dim, char * format, ...)
{
	va_list ap;
	va_start(ap, format);
	recursive_free(ptr, dim, format, ap);
	va_end(ap);
}
/*
 * ndimalloc allocate a mutidimensional array and return 
 * a pointer to that array. THe array elements are "size"
 * bytes.
 * */
void * ndimalloc(size_t size, size_t dim, char * format, ...)
{
	va_list ap;
	void * ret;

	va_start(ap,format);
	ret = recursive_alloc(size, dim, format, ap);
	va_end(ap);
	
	return ret;
}

