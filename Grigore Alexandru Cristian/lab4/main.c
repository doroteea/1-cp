#include <stdio.h>
#include <stdlib.h>
void addition(int **matB,int **matC,int **sum,int *rows,int *cols)
{
    int i,j;
    for(i=0;i<*rows;i++)
    {
        for(j=0;j<*cols;j++)
        {
            sum[i][j]=0;
            sum[i][j]=matB[i][j]+matC[i][j];
        }
    }
}
void substraction(int **matB,int **matC,int **sub,int *rows,int *cols)
{
    int i,j;
    for(i=0;i<*rows;i++)
    {
        for(j=0;j<*cols;j++)
        {
            sub[i][j]=0;
            sub[i][j]=matB[i][j]-matC[i][j];
        }
    }
}

int main()
{   int rows,cols,i,j;
int **sum,**sub;
    scanf("%d %d",&rows,&cols);
    int **matB=(int*)malloc(sizeof(int*)*rows);
        for(i=0;i<rows;i++)
        {
            matB[i]=(int*)malloc(sizeof(int)*cols);
        }
        for(i=0;i<rows;i++)
        {
            for(j=0;j<cols;j++)
            {
                printf("matB[%d][%d]",i,j);
                scanf("%d",&matB[i][j]);
            }
        }
    int **matC=(int*)malloc(sizeof(int*)*rows);
        for(i=0;i<rows;i++)
        {
            matC=(int*)malloc(sizeof(int)*cols);
        }
        for(i=0;i<rows;i++)
        {
            for(j=0;j<cols;j++)
            {
                printf("matC[%d][%d]",i,j);
                scanf("%d",&matC[i][j]);
            }
        }
        for(i=0;i<rows;i++)
        {
            sum=(int*)malloc(sizeof(int)*cols);
        }
        for(i=0;i<rows;i++)
        {
            sub=(int*)malloc(sizeof(int)*cols);
        }
        addition(&matB,&matC,&sum,&rows,&cols);
            printf("sum[%d][%d]",i,j);
        substraction(&matB,&matC,&sub,&rows,&cols);
            printf("sub[%d][%d]",i,j);



    return 0;
}
