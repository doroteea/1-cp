#include <stdio.h>
#include <stdlib.h>
int **matr,**prod;

void readMatr(int **matr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("matr[%d][%d]=",i,j);
            scanf("%d",&matr[i][j]);
        }
    }
}

void power(int **matr, int n, int **prod, int k)
{
    int e=2;

    int **matrp=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        matrp[i]=(int*)malloc(sizeof(int)*n);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrp[i][j]=matr[i][j];
        }
    }

    while(e<=k)
    {

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                prod[i][j]=0;

                for(int d=0; d<n; d++)
                {
                    prod[i][j]=prod[i][j]+matrp[i][d]*matr[d][j];
                }

            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                matrp[i][j]=prod[i][j];
            }
        }

        e=e+1;


    }

}

void printMatr(int **prod, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf(" %d",prod[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n,k;
    printf("Enter the dimension of the matrix ");
    scanf("%d",&n);

    printf("Enter the power of the matrix ");
    scanf("%d",&k);

    int **matr=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        matr[i]=(int*)malloc(sizeof(int)*n);
    }

    int **prod=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        prod[i]=(int*)malloc(sizeof(int)*n);
    }

    readMatr(matr,n);
    power(matr,n,prod,k);
    printMatr(prod,n);


    return 0;
}
