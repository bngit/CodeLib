#ifndef FUNC_H
#define FUNC_H

#define ROW 5
#define COL 20

/*
 * generate a dynamic 2-dim array
 * row and col are both offered by the user
 * */
void dyn_2arr(int *** arr, int col, int row);

/*
 * generate a dynamic 2-dim array
 * The row number is offered by the user
 * The col number is fixed.
 * */
void colfix_array(int (** col_arr)[COL], int row);

/*
 * generate a dynamic 2-dim array
 * The row number is fixed.
 * The col number is offered by the user
 * */
void rowfix_array(int * row_arr[], int col[]);

/*
 * generate a Multidimensional array
 * n --- the dimension number
 * ... --- the value of 1,2,3.. dimensions
 * */
void muti_arr(void * arr, int n, ...);

#endif /* ifndef FUNC_H_ */
