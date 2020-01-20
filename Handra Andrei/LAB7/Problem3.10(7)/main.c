#include <stdio.h>
#include <stdlib.h>

void printmatrix(int **,int,int);
void transposematrix(int**,int , int);

int main()
{
    int i,j,rows,col;
    printf("The number of rows is: ");
    scanf("%d",&rows);
    printf("The number of columns is: ");
    scanf("%d",&col);
    int **A=(int **)malloc(sizeof(int *)*rows);
    for(i=0;i<rows;i++)
    {
        A[i]=(int *)malloc(sizeof(int)*col);
    }
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("A[%d][%d]= ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("The matrix is:\n");
    printmatrix(A,rows,col);
    printf("The transposed matrix is: \n");
    transposematrix(A,rows,col);
    return 0;
}

void printmatrix(int **a,int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {

        for(j=0;j<m;j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
}
void transposematrix(int **a,int n,int m)
{
    int i,j;
    int **TransMatrix=(int **)malloc(sizeof(int *)*m);
    for(i=0;i<m;i++)
    {
        TransMatrix[i]=(int *)malloc(sizeof(int)*n);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            TransMatrix[j][i]=a[i][j];
        }
    }
    printmatrix(TransMatrix,m,n);
}
