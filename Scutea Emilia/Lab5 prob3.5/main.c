#include <stdio.h>
#include <stdlib.h>

int ** allocateMatrix(int n)
{
    int **mat=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        *(mat+i)=(int*)malloc(sizeof(int)*n);
    }
    return mat;
}


int ** readMatrix(int n)
{
    int **mat=allocateMatrix(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("Please input the element on the position %d %d: ",i,j);
            scanf("%d",(*(mat+i)+j));
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
            printf("%d ",*(*(mat+i)+j));
        }
        printf("\n");
    }
}

int ** addition(int ** mat1,int ** mat2,int n)
{
    int ** result=allocateMatrix(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            *(*(result+i)+j) = *(*(mat1+i)+j) + *(*(mat2+i)+j);
        }
    }
    return result;
}

int ** subtraction(int ** mat1,int ** mat2,int n)
{
    int ** result=allocateMatrix(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            *(*(result+i)+j) = *(*(mat1+i)+j) - *(*(mat2+i)+j);
        }
    }
    return result;
}

int ** multiplication(int ** mat1,int ** mat2,int n)
{
    int ** result=allocateMatrix(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            *(*(result+i)+j)=0;
        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                *(*(result+i)+j) += *(*(mat1+i)+j) * *(*(mat2+i)+j);
            }
        }
    }
    return result;

}

int ** multiplyWithInteger(int ** mat,int n,int num)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            *(*(mat+i)+j) = num * *(*(mat+i)+j);
        }
    }
    return mat;
}

int main()
{
    int n;
    printf("Please input the order of the matrix: \nn=");
    scanf("%d",&n);

    int ** B = readMatrix(n);
    printf("The matrix B is:\n");
    printMatrix(B,n);

    int ** C = readMatrix(n);
    printf("The matrix C is:\n");
    printMatrix(C,n);

    int ** D =addition(B,C,n);
    printf("The matrix of addition is:\n");
    printMatrix(D,n);

    int ** E =subtraction(B,C,n);
    printf("The matrix of subtraction is:\n");
    printMatrix(E,n);

    int ** F =multiplication(B,C,n);
    printf("The matrix of multiplication is:\n");
    printMatrix(F,n);

    int ** A=allocateMatrix(n);
    D=multiplyWithInteger(D,n,2);
    A=subtraction(F,D,n);
    printf("The matrix A=B*C-2*(B+C) is:\n");
    printMatrix(A,n);

}
