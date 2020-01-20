#include <stdio.h>
#include <stdlib.h>
int n;
int addition(int **mat1,int **mat2)
{

    int r,c,i;
    int **mat3=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        mat3[i]=(int*)malloc(sizeof(int)*n);
    }
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            mat3[r][c]=0;
        }
    }
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            mat3[r][c]=mat1[r][c]+mat2[r][c];
        }
    }
    return mat3;
}
int subtraction(int **mat1,int **mat2)
{
    int r,c,i;
    int **mat3=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        mat3[i]=(int*)malloc(sizeof(int)*n);
    }
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            mat3[r][c]=0;
        }
    }
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            mat3[r][c]=mat1[r][c]-mat2[r][c];
        }
    }
    return mat3;
}
int multiplication(int **mat1,int **mat2)
{
    int r,c,i,sum=0;
    int **mat3=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        mat3[i]=(int*)malloc(sizeof(int)*n);
    }
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            mat3[r][c]=0;
        }
    }
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            for(i=0; i<n; i++)
            {
                sum=sum+mat1[r][i]*mat2[i][c];
            }
            mat3[r][c]=sum;
            sum=0;
        }
    }
    return mat3;
}
int main()
{
    printf("Hello world!\n");
    int i,r,c;
    printf("insert nr of rows and columns\n");
    scanf("%d",&n);
    int **mat1=(int**)malloc(sizeof(int*)*n);
    int **mat2=(int**)malloc(sizeof(int*)*n);
    int **mat3=(int**)malloc(sizeof(int*)*n);
     int **A=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        mat1[i]=(int*)malloc(sizeof(int)*n);
        mat2[i]=(int*)malloc(sizeof(int)*n);
        mat3[i]=(int*)malloc(sizeof(int)*n);
        A[i]=(int*)malloc(sizeof(int)*n);
    }
    printf("insert matrix 1 and matrix 2\n");
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            scanf("%d ",&mat1[r][c]);
        }
    }
    for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            scanf("%d",&mat2[r][c]);
        }
    }
    A= multiplication(mat1,mat2);
    mat3= addition(mat1,mat2);
     for(r=0; r<n; r++)
    {
        for(c=0; c<n; c++)
        {
            mat3[r][c]=mat3[r][c]*2;
        }
    }
    A=subtraction(A,mat3);
    for(r=0;r<n;r++)
    {
        for(c=0; c<n; c++)
        {
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }
    return 0;
}
