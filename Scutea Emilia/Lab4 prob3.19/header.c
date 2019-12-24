#include <stdio.h>
#include <stdlib.h>

int **readMatrix(int n)
{
    int **mat=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
    {
        mat[i]=(int*)malloc(sizeof(int)*n);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Please input the value of a[%d][%d]:\na[%d][%d]=",i,j,i,j);
            scanf("%d",&mat[i][j]);
        }
    }
    return mat;
}

void printMatrix(int **mat,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }

}

int verifySymmetry(int **mat,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]!=mat[j][i])
                return 0;
        }
    }
    return 1;
}
