#include <stdio.h>
#include <stdlib.h>

void* allocMatrix (int n)
{
    return malloc (sizeof(int[n][n]));
}

void readMatrix (int n, int (*matrix)[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("matrix[%d][%d]: ", i+1, j+1);
            scanf("%d", &*(*(matrix + i) + j));
        }
    }
}

void printMatrix (int n, int (*matrix)[n])
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void multiplyMatrices(int n, int (*matrix1)[n], int (*matrix2)[n], int (*product)[n])
{
    int i, j, k;
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            *(*(product + i) + j) = 0;
        }
    }

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            for(k=0; k<n; ++k)
            {
                *(*(product + i) + j) += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
            }
        }
    }
}

int main()
{
    int n; //number of lines and columns in the two matrices
    printf("Please insert number of lines/columns for the square matrix: ");
    scanf("%d", &n);

    int(*mat1)[n] = allocMatrix(n);
    printf("Please insert values for the first matrix: \n");
    readMatrix(n, mat1);
    printf("The first matrix is: \n");
    printMatrix(n,mat1);

    int(*mat2)[n] = allocMatrix(n);
    printf("Please insert values for the second matrix: \n");
    readMatrix(n, mat2);
    printf("The second matrix is: \n");
    printMatrix(n,mat2);

    int(*product)[n] = allocMatrix(n);

    multiplyMatrices(n,mat1,mat2,product);

    printf("The two matrices multiplied are: \n");
    printMatrix(n,product);

    return 0;
}