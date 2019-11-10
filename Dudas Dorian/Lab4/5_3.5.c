#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows,cols;
    printf("give a value for the rows and collumns: ");
    scanf("%d",&rows);
    cols=rows;

    int**B=(int*)malloc(sizeof(int*)*rows);
    for(int i=0; i<rows; i++)
    {
        B[i]=(int*)malloc(sizeof(int)*cols);
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
        }
    }

    int**C=(int*)malloc(sizeof(int*)*rows);
    for(int i=0; i<rows; i++)
    {
        C[i]=(int*)malloc(sizeof(int)*cols);
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("C[%d][%d]=",i,j);
            scanf("%d",&C[i][j]);
        }
    }

    int**ADD=(int*)malloc(sizeof(int*)*rows);
    for(int i=0; i<rows; i++)
    {
        ADD[i]=(int*)malloc(sizeof(int)*cols);
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            ADD[i][j]=0;
            ADD[i][j]=B[i][j]+C[i][j];
            printf("ADD[%d][%d]=%d\n",i,j,ADD[i][j]);
        }
    }

    int**DIF=(int*)malloc(sizeof(int*)*rows);
    for(int i=0; i<rows; i++)
    {
        DIF[i]=(int*)malloc(sizeof(int)*cols);
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            DIF[i][j]=0;
            DIF[i][j]=B[i][j]-C[i][j];
            printf("DIF[%d][%d]=%d\n",i,j,DIF[i][j]);
        }
    }

    int**PROD=(int*)malloc(sizeof(int*)*rows);
    for(int i=0; i<rows; i++)
    {
        PROD[i]=(int*)malloc(sizeof(int)*cols);
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            PROD[i][j]=0;
            PROD[i][j]=B[i][j]*C[i][j];
            printf("PROD[%d][%d]=%d\n",i,j,PROD[i][j]);
        }
    }

    int**A=(int*)malloc(sizeof(int*)*rows);
    for(int i=0; i<rows; i++)
    {
        A[i]=(int*)malloc(sizeof(int)*cols);
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            A[i][j]=0;
            A[i][j]=B[i][j]*C[i][j]-2*(B[i][j]+C[i][j]);
            printf("A[%d][%d]=%d\n",i,j,A[i][j]);
        }
    }
    return 0;
}
