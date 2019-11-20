#include <stdio.h>
#include <stdlib.h>
void read(int **mat,int rows,int cols)
{
    int r,c;
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            printf("mat[%d][%d]= ",r,c);
            scanf("%d",&mat[r][c]);
        }
    }
}
void print(int **mat,int rows,int cols)
{
    int r,c;
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            printf("%d \t",mat[r][c]);
        }
        printf("\n");
    }


}
void addition(int **mat1,int **mat2,int **mat3,int rows,int cols)
{
    int r,c;
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            mat3[r][c]=mat1[r][c]+mat2[r][c];
        }
    }
}
void subtraction(int **mat1,int **mat2,int **mat3,int rows,int cols)
{
    int r,c;
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            mat3[r][c]=mat1[r][c]-mat2[r][c];
        }
    }
}
void multiplication(int **mat1,int **mat2,int **mat3,int rows,int cols)
{
    int r,c,s,x;
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            s=0;
            for(x=0; x<rows; x++)
            {
                s=s+mat1[r][x]*mat2[x][c];
            }
            mat3[r][c]=s;
        }

    }
}
///oricare ar fi un scalar - cazul general
void scalar_multiplication(int **mat1,int **mat2,int rows,int cols,int scalar)
{
    int r,c;
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            mat2[r][c]= scalar*mat1[r][c];
        }

    }
}
int main()
{
    int i,n,rows,cols,scalar;
    printf("Enter order of matrix: ");
    scanf("%d",&n);
    printf("Enter a scalar: ");
    scanf("%d",&scalar);
    rows=n;
    cols=n;
    int **b=(int**)malloc(sizeof(int)*rows);
    for(i=0; i<rows; i++)
    {
        b[i]=(int*)malloc(sizeof(int)*cols);
    }
    int **c=(int**)malloc(sizeof(int)*rows);
    for(i=0; i<rows; i++)
    {
        c[i]=(int*)malloc(sizeof(int)*cols);
    }
    int **add=(int**)malloc(sizeof(int)*rows);
    for(i=0; i<rows; i++)
    {
        add[i]=(int*)malloc(sizeof(int)*cols);
    }
    int **sub=(int**)malloc(sizeof(int)*rows);
    for(i=0; i<rows; i++)
    {
        sub[i]=(int*)malloc(sizeof(int)*cols);
    }
    int **multiply=(int**)malloc(sizeof(int)*rows);
    for(i=0; i<rows; i++)
    {
        multiply[i]=(int*)malloc(sizeof(int)*cols);
    }
    int **smultiply=(int**)malloc(sizeof(int)*rows);
    for(i=0; i<rows; i++)
    {
        smultiply[i]=(int*)malloc(sizeof(int)*cols);
    }
    int **a=(int**)malloc(sizeof(int)*rows);
    for(i=0; i<rows; i++)
    {
        a[i]=(int*)malloc(sizeof(int)*cols);
    }
    printf("\nEnter the elements of B:\n");
    read(b,rows,cols);
    printf("\nEnter the elements of C:\n");
    read(c,rows,cols);
    addition(b,c,add,rows,cols);
    ///printf("\nSum matrix is:\n");
    ///print(add,rows,cols);
    subtraction(b,c,sub,rows,cols);
    ///printf("\nDifference matrix is:\n");
    ///print(sub,rows,cols);
    multiplication(b,c,multiply,rows,cols);
    ///printf("\nProduct matrix is:\n");
    ///print(multiply,rows,cols);
    scalar_multiplication(add,smultiply,rows,cols,scalar);
    ///printf("\nMultiplication with %d is:\n",scalar);
    ///print(smultiply,rows,cols);
    subtraction(multiply,smultiply,a,rows,cols);
    printf("\nMatrix A:\n");
    print(a,rows,cols);
    return 0;
}
