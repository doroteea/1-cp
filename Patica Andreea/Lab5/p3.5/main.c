#include <stdio.h>
#include <stdlib.h>

int rows=4, cols=4;

int** addition(int **B, int **C)
{
    int **A=(int)malloc(sizeof(int*)*rows);
    for (int i=0; i<rows; i++)
    {
        A[i]=(int*)malloc(sizeof(int)*cols);
    }

    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<cols; c++)
        {
            A[r][c]=B[r][c]+C[r][c];
        }
    }
    return **A;
}

int** substraction(int **B, int **C)
{
    int **A=(int)malloc(sizeof(int*)*rows);
    for (int i=0; i<rows; i++)
    {
        A[i]=(int*)malloc(sizeof(int)*cols);
    }

    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<cols; c++)
        {
            A[r][c]=B[r][c]-C[r][c];
        }
    }
    return **A;
}

int** multiplication(int **B, int **C)
{
    int **A=(int)malloc(sizeof(int*)*rows);
    for (int i=0; i<rows; i++)
    {
        A[i]=(int*)malloc(sizeof(int)*cols);
    }

//    for (int r=0; r<rows; r++)
//    {
//        for (int c=0; c<cols; c++)
//        {
//
//        }
//    }
    return **A;
}


int main()
{

    int **B=(int)malloc(sizeof(int*)*rows);
    for (int i=0; i<rows; i++)
    {
        B[i]=(int*)malloc(sizeof(int)*cols);
    }

    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<cols; c++)
        {
            printf("B[%d][%d]=", r, c);
            scanf("%d", &B[r][c]);
            printf("\n");
        }
    }

    int **C=(int)malloc(sizeof(int*)*rows);
    for (int i=0; i<rows; i++)
    {
        C[i]=(int*)malloc(sizeof(int)*cols);
    }

    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<cols; c++)
        {
            printf("C[%d][%d]=", r, c);
            scanf("%d", &C[r][c]);
            printf("\n");
        }
    }

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }


    return 0;
}
