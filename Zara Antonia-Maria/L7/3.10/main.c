#include <stdio.h>
#include <stdlib.h>

///asta functioneaza

int ** readMatrix(int n)
{
    int i,cols,rows;
    cols=n;
    rows=n;
    int **mat= (int**)malloc(sizeof(int*)*cols);
    for(i=0; i<cols; i++)
    {
        mat[i]= (int*)malloc(sizeof(int)*rows);
    }
    int r,c;
    printf("Input matrix: \n");
    for(r=0; r<rows; r++)
        for(c=0; c<cols; c++)
        {
            scanf("%d",&mat[r][c]);
        }
    return mat;
}

void printMatrix(int **mat,int rows)
{
    int i,j;
    printf("The transposed of the matrix is: \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<rows;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}

int main()
{
    int i,j,rows;

    printf("Input number of rows of matrix: ");
    scanf("%d",&rows);

    int **matrix= (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        matrix[i]= (int*)malloc(sizeof(int)*rows);
    }

    ///the transposed
    int **T = (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        T[i]= (int*)malloc(sizeof(int)*rows);
    }

    matrix = readMatrix(rows);

    for(i=0;i<rows;i++)
        for(j=0;j<rows;j++)
            T[i][j]=matrix[j][i];

    printMatrix(T,rows);

    return 0;
}
