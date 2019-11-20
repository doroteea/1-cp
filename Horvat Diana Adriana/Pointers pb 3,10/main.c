#include <stdio.h>
#include <stdlib.h>
int **matr, **trmatr;

void readMatr(int **matr, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("matr[%d][%d]=",i,j);
            scanf("%d",&matr[i][j]);
        }
    }
}

void transposedMatr(int **matr, int **trmatr, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            trmatr[j][i]=matr[i][j];
    }
}

void printMatr(int **trmatr, int n, int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
             printf(" %d",trmatr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n,m;
    printf("Enter the dimension of the matrix n=");
    scanf("%d",&n);
    printf(" m=");
    scanf("%d",&m);

    int **matr=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        matr[i]=(int*)malloc(sizeof(int)*m);
    }

     int **trmatr=(int**)malloc(sizeof(int*)*m);
    for(int i=0; i<m; i++)
    {
        trmatr[i]=(int*)malloc(sizeof(int)*n);
    }

    readMatr(matr,n,m);
    transposedMatr(matr,trmatr,n,m);
    printMatr(trmatr,n,m);

    return 0;
}
