#include <stdio.h>
#include <stdlib.h>


void addition(int **K,int **B,int **C,int rows, int cols)
{
    int i,j;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            K[i][j] = B[i][j] + C[i][j];
        }
    }
}

void subtraction(int **A, int **P, int **K, int rows, int cols)
{
    int i,j;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            A[i][j] = P[i][j]-K[i][j];
        }
    }
}

void product(int **P, int **B, int **C, int rows, int cols)
{
    int i,j,k,s;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            s=0;
            for(k=0; k<rows; k++)
            {
                s = s+B[i][k]*C[k][j];
            }
            P[i][j] = s;
        }

    }
}

int main()
{
    int rows,cols,i,j;
    scanf("%d %d",&rows,&cols);
    int **B = (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        B[i] = (int*)malloc(sizeof(int)*cols);
    }
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    int **C = (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        C[i] = (int*)malloc(sizeof(int)*cols);
    }
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            scanf("%d",&C[i][j]);
        }
    }
    int **A = (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        A[i] = (int*)malloc(sizeof(int)*cols);
    }
    int **K = (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        K[i] = (int*)malloc(sizeof(int)*cols);
    }
    int **P = (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        P[i] = (int*)malloc(sizeof(int)*cols);
    }

    addition(K,B,C,rows,cols);
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            K[i][j] = K[i][j]*2;
        }
    }
    product(P,B,C,rows,cols);
    subtraction(A,P,K,rows,cols);
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
