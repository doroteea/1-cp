#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

float **addition(int *size, float **A, float **B)
{
    float **sum=(float**)malloc(sizeof(float*)*MAXSIZE);
    int i,j;
    for(i=0; i<(*size); i++)
    {
        *(sum+i+1)=(float*)malloc(sizeof(float)*MAXSIZE);
    }
    for(i=0; i<(*size); i++)
    {
        for(j=0; j<(*size); j++)
        {
            sum[i+1][j+1]=A[i+1][j+1]+B[i+1][j+1]*2;
        }
    }
    return sum;
}

float **difference(int *size, float **A, float **B)
{
    float **difference=(float**)malloc(sizeof(float*)*MAXSIZE);
    int i,j;
    for(i=0; i<(*size); i++)
    {
        *(difference+i+1)=(float*)malloc(sizeof(float)*MAXSIZE);
    }
    for(i=0; i<(*size); i++)
    {
        for(j=0; j<(*size); j++)
        {
            difference[i+1][j+1]=A[i+1][j+1]-B[i+1][j+1];
        }
    }
    return difference;
}

float **multiply(int *size, float **A, float **B)
{
    int i,j,k;
    float **product=(float**)malloc(sizeof(float*)*MAXSIZE);
    for(i=0; i<(*size); i++)
    {
        *(product+i+1)=(float*)malloc(sizeof(float)*MAXSIZE);
    }
    for(i=0; i<*size; i++)
    {
        for(j=0; j<*size; j++)
        {
            product[i+1][j+1]=0;
            for(k=0; k<*size; k++)
            {
                product[i+1][j+1]+=A[i+1][k+1]*B[k+1][j+1];
            }
        }
    }
    return product;
}
int main()
{
    int i, j, size;

    printf("\nPlease input the size of your quadratic matrices:");
    scanf("%d",&size);

    float **A=(float**)malloc(sizeof(float*)*MAXSIZE);
    float **B=(float**)malloc(sizeof(float*)*MAXSIZE);
    float **C=(float**)malloc(sizeof(float*)*MAXSIZE);

    for(i=0; i<size; i++)
    {
        *(A+i+1)=(float*)malloc(sizeof(float)*size);
    }
    for(i=0; i<size; i++)
    {
        *(B+i+1)=(float*)malloc(sizeof(float)*size);/*Hey Alex, why doesn't it allocate enough space if I write simply *(A+I)?*/
    }
    for(i=0; i<size; i++)
    {
        *(C+i+1)=(float*)malloc(sizeof(float)*size);
    }


    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("\nB[%d][%d]=",i+1,j+1);
            scanf("%f",&A[i+1][j+1]);
        }

    }

    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("\nC[%d][%d]=",i+1,j+1);
            scanf("%f",&B[i+1][j+1]);
        }
    }
    A=difference(&size, multiply(&size,B,C), addition(&size, B, C));
    printf("\nA=");
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("\nA[%d][%d]=%f",i+1,j+1,A[i+1][j+1]);
        }
    }

    return 0;
}
