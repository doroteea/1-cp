#include <stdio.h>
#include <stdlib.h>

int** Multiplication (int **A, int **B, int n)
{
    int i, j, s, z;
    int **C = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        C[i] = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
             s = 0;
             for (z = 0; z < n; z++)
                s = s + A[i][z] * B[z][j];
             C[i][j] = s;
        }
    }
    return C;
}

int** calculatingPower (int **A, int n, int k)
{
    int i, j;
    int **B = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        B[i] = (int*)malloc(sizeof(int) * n);
    if (k == 0)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    B[i][j] = 1;
                }
                else
                {
                    B[i][j] = 0;
                }
            }
        }
        return B;
    }
    B = A;
    for (i = 1; i < k; i++)
    {
        A = Multiplication (A, B, n);
    }
    return A;
}

int main ()
{
    int n, k, i, j;
    printf ("order of the matrix = ");
    scanf ("%d", &n);
    int **A = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        A[i] = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf ("%d", &A[i][j]);
        }
    }
    printf ("power = ");
    scanf ("%d", &k);
    A = calculatingPower (A, n, k);
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
