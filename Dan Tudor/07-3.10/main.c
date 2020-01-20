#include <stdio.h>
#include <stdlib.h>
void scanMatrix(int **a, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void calculateTranspose(int **a, int **b, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            b[j][i] = a[i][j];
        }
    }
}

void printMatrix(int **a, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows,cols;
    scanf("%d",&rows);
    scanf("%d",&cols);
    int **mat=(int**)malloc(sizeof(int*)*rows);
    for(int i=0; i<rows; i++)
    {
        mat[i] = (int*)malloc(sizeof(int)*cols);
    }
    int **transp=(int**)malloc(sizeof(int*)*cols);
    for(int i=0; i<cols; i++)
    {
        transp[i] = (int*)malloc(sizeof(int)*rows);
    }
    scanMatrix(mat,rows,cols);
    calculateTranspose(mat,transp,rows,cols);
    printMatrix(transp,cols,rows);
    return 0;
}
