#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ROW 5
#define COL 20

/*
 * generate a dynamic 2-dim array
 * row and col are both not fixed
 * */
int dyn_2arr(int *** arr, int col, int row)
{
	int i;
	*arr = malloc(sizeof(int *) * row);
	for (i = 0; i < row; i++)
		*(*arr + i) = malloc(sizeof(int) * col);

	return 0;
}

/*
 * generate a dynamic 2-dim array
 * The row number is offered by the user
 * The col number is fixed.
 * */
int colfix_array(int (** col_arr)[COL], int row)
{
	*col_arr = malloc(sizeof(int (*)[COL]) * row);

	return 0;
}

/*
 * generate a dynamic 2-dim array
 * The row number is fixed.
 * The col number is offered by the user
 * */
int rowfix_array(int * row_arr[], int col[])
{
	int i;
	for (i = 0; i < ROW; i++) {
		row_arr[i] = malloc(sizeof(int) * col[i]);
	}

	return 0;
}

/*
 * generate a multidimensional array
 * */
static int stmuti_arr(void ** arr, int n,  va_list ap)
{
	int size;
	int i;
	if (n <= 0) {
		*arr = NULL;
		return 0;
	}
	if ( n == 1) {
		*arr = malloc(sizeof(int) * va_arg(ap, int));
		return 0;
	}
	if (n == 2) {
		dyn_2arr((int ***)arr, va_arg(ap, int), va_arg(ap, int));
		return 0;
	}
	size = va_arg(ap, int);
	*arr = malloc(sizeof(void *) * size);
	va_list ap0;
	va_copy(ap0, ap);  // for C99 only
	for (i = 0; i < size; i++) {
		va_copy(ap, ap0);
		stmuti_arr(*arr + i * sizeof(void *), n-1, ap);
	}

	return 0;
}

/*
 * generate a Multidimensional array
 * n --- the dimension number
 * ... --- the value of 1,2,3.. dimensions
 * */
int muti_arr(void * arr, int n, ...)
{
	va_list ap;
	va_start(ap, n);
	stmuti_arr(arr, n, ap);
	va_end(ap);
	return 0;
}


int main()
{
	/* test for rowfix_array */
	int * row_arr[ROW];
	int col[] = {2, 3, 4, 5, 3};
	rowfix_array(row_arr, col);
	row_arr[1][2] = 23;
	row_arr[4][4] = 91;
	printf("%d %d\n", row_arr[1][2], row_arr[4][4]);

	/* test for colfix_array */
	int (* col_arr)[COL];
	colfix_array(&col_arr, 5);
	col_arr[0][0] = 42;
	col_arr[4][19] = 29;
	printf("%d %d\n", col_arr[0][0], col_arr[4][19]);

	/* test for dyn_array */
	int ** arr;
	dyn_2arr(&arr, 4, 5);
	arr[0][0] = 23;
	arr[3][4] = 22;
	printf("%d %d\n", arr[0][0], arr[3][4]);
	
	/* test for muti_arr */
	int ***** marr;
	muti_arr(&marr, 5, 3, 4, 5, 2, 23);
	marr[2][3][4][1][22] = 23;
	printf("%d\n", marr[2][3][4][1][22]);

	return 0;
}
