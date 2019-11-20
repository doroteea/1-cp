#include <stdio.h>
#include <stdlib.h>

int** Addition (int **B, int **C, int n)
{
    int i, j;
    int **A1 = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        A1[i] = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A1[i][j] = B[i][j] + C[i][j];
        }
    }
    return A1;
}

int** Subtraction (int **B, int **C, int n)
{
    int i, j;
    int **A1 = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        A1[i] = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A1[i][j] = B[i][j] - C[i][j];
        }
    }
    return A1;
}

int** MultiplicationWithAScalar (int **B, int n, int s)
{
    int i, j;
    int **A1 = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        A1[i] = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A1[i][j] = B[i][j] * s;
        }
    }
    return A1;
}

int** Multiplication (int **B, int **C, int n)
{
    int i, j, s, z;
    int **A1 = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        A1[i] = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
             s = 0;
             for (z = 0; z < n; z++)
                s = s + B[i][z] * C[z][j];
             A1[i][j] = s;
        }
    }
    return A1;
}

int main()
{
    int n, i, j;
    printf ("the order of the two matrices (B and C) is n = ");
    scanf ("%d", &n);
    int **A = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        A[i] = (int*)malloc(sizeof(int) * n);
    int **B = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        B[i] = (int*)malloc(sizeof(int) * n);
    int **C = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        C[i] = (int*)malloc(sizeof(int) * n);
    printf ("the elements of B are: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf ("\nB[%d][%d] = ", i, j);
            scanf ("%d", &B[i][j]);
        }
    }
    printf ("the elements of C are: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf ("\nC[%d][%d] = ", i, j);
            scanf ("%d", &C[i][j]);
        }
    }

    A = Subtraction (Multiplication (B, C, n), MultiplicationWithAScalar (Addition (B, C, n), n, 2), n);
    printf ("the result-matrix A is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf ("%d ", A[i][j]);
        }
        printf ("\n");
    }

    return 0;
}
