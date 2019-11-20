#include <stdio.h>
#include <stdlib.h>

int** transposedMatrix (int **A, int rows, int cols)
{
    int i, j;
    int **At = (int**)malloc(sizeof (int*) * cols);
    for (i = 0; i < cols; i++)
    {
        At[i] = (int*)malloc(sizeof (int) * rows);
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            At[j][i] = A[i][j];
        }
    }
    return At;
}

int main ()
{
    int i, j, rows, cols;
    printf ("number of rows = ");
    scanf ("%d", &rows);
    printf ("number of columns = ");
    scanf ("%d", &cols);
    int **A = (int**)malloc(sizeof (int*) * rows);
    for (i = 0; i < rows; i++)
    {
        A[i] = (int*)malloc(sizeof (int) * cols);
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf ("%d", &A[i][j]);
        }
    }

    int **At = (int**)malloc(sizeof (int*) * cols);
    for (i = 0; i < cols; i++)
    {
        At[i] = (int*)malloc(sizeof (int) * rows);
    }

    At = transposedMatrix (A, rows, cols);
    printf ("the transposed of the matrix is:\n");
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            printf ("%d ", At[i][j]);
        }
        printf ("\n");
    }

    return 0;
}
