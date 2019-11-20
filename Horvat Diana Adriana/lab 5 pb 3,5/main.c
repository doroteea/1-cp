#include <stdio.h>
#include <stdlib.h>
int n;
void prod(int **x, int **y, int **z, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            x[i][j]=0;

            for(int k=0; k<n; k++)
            {
                x[i][j]=x[i][j]+(y[i][k]*z[k][j]);
            }
        }
    }

}
void sum(int **x, int **y, int **z, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            x[i][j]=(y[i][j]+z[i][j])*2;
        }
    }

}
void sub(int **x, int **y, int **z, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            x[i][j]=y[i][j]-z[i][j];
        }
    }

}
int **a,**b,**c,**aux1,**aux2;
int main()
{
    scanf("%d",&n);

    int **aux2=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        aux2[i]=(int*)malloc(sizeof(int)*n);
    }

    int **aux1=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        aux1[i]=(int*)malloc(sizeof(int)*n);
    }

    int **a=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        a[i]=(int*)malloc(sizeof(int)*n);
    }

    int **b=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        b[i]=(int*)malloc(sizeof(int)*n);
    }

    int **c=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        c[i]=(int*)malloc(sizeof(int)*n);
    }

    for(int i=0; i<n; i++)
    {

        for(int j=0; j<n; j++)
        {
            printf("b[%d][%d]=",i,j);
            scanf("%d",&b[i][j]);
        }
    }

    for(int i=0; i<n; i++)
    {

        for(int j=0; j<n; j++)
        {
            printf("c[%d][%d]=",i,j);
            scanf("%d",&c[i][j]);
        }
    }

    prod(aux1,b,c,n);
    sum(aux2,b,c,n);
    sub(a,aux1,aux2,n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf(" %d",a[i][j]);
        }
        printf("\n");


    }

    return 0;
}
