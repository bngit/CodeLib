#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 20

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

	if (row_arr == NULL) {
		fprintf(stderr, "row_arr is NULL!\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < ROW; i++) {
		row_arr[i] = malloc(sizeof(int) * col[i]);
	}

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

	return 0;
}
