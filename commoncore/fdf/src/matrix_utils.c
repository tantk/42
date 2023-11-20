#include "../includes/fdf.h"

int *mat_col(t_matrix *mat, int col)
{
    int counter;
    int *col_values;
    int mat_row;
    int mat_col;

    mat_row = mat -> mat_row;
    mat_col = mat -> mat_col;
    col_values = (int *)malloc(mat_row * sizeof(int));
    if (!col_values)
        exit_error("mat_col: malloc fails");
    counter = 0;
    while (counter < mat_row)
    {
        col_values[counter] = mat -> content [counter * mat_col + col]
        counter++;
    }
    return (col_values);
}
