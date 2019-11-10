#include <stdio.h>
#include <stdlib.h>
int n;
void addition(int **mat1, int **mat2, int **A, int *n)
{
    int i,j;
    for(i=0; i<*n; i++)
    {
        for(j=0; j<*n; j++)
        {
            A[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}
void substraction(int **mat1, int **mat2, int **A, int *n)
{
    int i,j;
    for(i=0; i<*n; i++)
    {
        for(j=0; j<*n; j++)
        {
            A[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
}
/*void multiplication(int **mat1, int **mat2, int **A, int *n)
{
    int i,j,a;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            A[i][j]=0;
            for(a=0; a<n; a++)
            {
                A[i][j]=A[i][j]+mat1[i][a]*mat2[a][j];
            }
        }
    }
}*/
int main()
{
    scanf("%d",&n);
    int i,j;
    int **mat1=(int*)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        mat1[i]=(int*)malloc(sizeof(int)*n);
    }
    int **mat2=(int*)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        mat2[i]=(int*)malloc(sizeof(int)*n);
    }
    int **A=(int*)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        A[i]=(int*)malloc(sizeof(int)*n);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("mat1[%d][%d]=",i,j);
            scanf("%d",&mat1[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("mat2[%d][%d]=",i,j);
            scanf("%d",&mat2[i][j]);
        }
    }
    addition(mat1,mat2,A,&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    substraction(mat1,mat2,A,&n);
    printf("\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    /*multiplication(mat1,mat2,A,&n);
    printf("\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}
