#include <stdio.h>
#include <stdlib.h>


void addition(int **MatB,int **MatC,int **MatA,int rows,int col)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            MatA[i][j]=MatB[i][j]+MatC[i][j];
        }
    }

}
void subtraction(int **MatB,int **MatC,int **MatA,int rows, int col)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            MatA[i][j]=MatB[i][j]-MatC[i][j];
        }
    }
}
void multiplication(int **MatB,int **MatC,int **MatA,int rows,int col)
{
    int i,j,k;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            MatA[i][j]=0;
        }
    }
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            for(k=0;k<rows;k++)
            {
                MatA[i][j]=MatA[i][j]+MatB[i][k]*MatC[k][j];
            }
        }
    }
}
void printmatrix(int **MatA,int rows,int col)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",MatA[i][j]);
        }
        printf("\n");
    }
}
void compute(int **MatB,int **MatC,int **MatA,int rows,int col)
{
    int i,j;
    int **MatD=(int**)malloc(sizeof(int*)*rows);
    for(i=0;i<rows;i++)
    {
        MatD[i]=(int*)malloc(sizeof(int)*col);
    }
    addition(MatB,MatC,MatD,rows,col);
    multiplication(MatB,MatC,MatA,rows,col);
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            MatA[i][j]=MatA[i][j]-2*MatD[i][j];
        }
    }

}
int main()
{
    int i,j;
    int col,rows;
    printf("Give the number of rows and columns: ");
    scanf("%d",&col);
    rows=col;
    int **MatB=(int**)malloc(sizeof(int*)*rows);
    for(i=0;i<rows;i++)
    {
        MatB[i]=(int*)malloc(sizeof(int)*col);
    }

    int **MatC=(int**)malloc(sizeof(int*)*rows);
    for(i=0;i<rows;i++)
    {
        MatC[i]=(int*)malloc(sizeof(int)*col);
    }

    int **MatA=(int**)malloc(sizeof(int*)*rows);
    for(i=0;i<rows;i++)
    {
        MatA[i]=(int*)malloc(sizeof(int)*col);
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("MatB[%d][%d]= ",i,j);
            scanf("%d",&MatB[i][j]);
        }
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("MatC[%d][%d]= ",i,j);
            scanf("%d",&MatC[i][j]);
        }
    }
    compute(MatB,MatC,MatA,rows,col);
    printf("A=B*C-2*(B+C)= ");
    printmatrix(MatA,rows,col);
    return 0;
}
