#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "func.h"
#include "general_func.h"

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

	/* test for ndimalloc & ndimfree */
	int * nnarr;
	nnarr = ndimalloc(sizeof(int), 1, "d", 23);
	nnarr[22] = 234;
	printf("%d\n", nnarr[22]);
	ndimfree(nnarr, 1, "d", 23);

	int ** n2dimarr;
	n2dimarr = ndimalloc(sizeof(int), 2, "d", 2, 3);
	n2dimarr[1][2] = 123;
	printf("%d\n", n2dimarr[1][2]);
	ndimfree(n2dimarr, 2, "d", 2, 3);

	int ******* ndimarr;
	ndimarr = ndimalloc(sizeof(int), 7, "d", 3, 4, 2, 4, 3, 4, 3);
	ndimarr[2][3][1][3][2][3][2] = 23;
	printf("%d\n", ndimarr[2][3][1][3][2][3][2]);
	ndimfree(ndimarr, 7, "d", 3, 4, 2, 4, 3, 4, 3);

	return 0;
}
