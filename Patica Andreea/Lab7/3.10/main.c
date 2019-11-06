#include <stdio.h>
#include <stdlib.h>

int** transposedMatrix(int **A, int rank)
{
    int **B =(int**)malloc(sizeof(int)*rank);
    for (int i=0; i<rank; i++)
    {
        B[i]=(int*)malloc(sizeof(int)*rank);
    }

    for (int i=0; i<rank; i++)
    {
        for (int j=0; j<rank; j++)
        {
            B[i][j]=A[j][i];
        }
    }
    return B;
}

int main()
{

    int rank;
    printf("Insert the rank of the matrix!\n");
    scanf("%d", &rank);


    int **mat =(int**)malloc(sizeof(int)*rank);
    for (int i=0; i<rank; i++)
    {
        mat[i]=(int*)malloc(sizeof(int)*rank);
    }


    for (int i=0; i<rank; i++)
    {
        for (int j=0; j<rank; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int **A =(int**)malloc(sizeof(int)*rank);
    for (int i=0; i<rank; i++)
    {
        A[i]=(int*)malloc(sizeof(int)*rank);
    }

    A=transposedMatrix(mat, rank);
    for (int i=0; i<rank; i++)
    {
        for (int j=0; j<rank; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
