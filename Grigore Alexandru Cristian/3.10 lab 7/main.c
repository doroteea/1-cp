#include <stdio.h>
#include <stdlib.h>
int **findtranspose(int **A,int n,int **transpose)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            transpose[j][i]=A[i][j];
        }
    }
    return transpose;
}
void printtranspose(int **transpose,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",transpose[i][j]);
            if(j==n-1)
            {
                printf("\n\n");
            }
        }
    }
}
int main()
{
    int **A,**transpose,n,i,j;
    printf("Enter rows and cols:");
    scanf("%d",&n);
    A=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
    {
        A[i]=(int*)malloc(sizeof(int)*n);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("A[%d[%d]",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    transpose=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
    {
        transpose[i]=(int*)malloc(sizeof(int)*n);
    }
    findtranspose(A,n,transpose);
    printtranspose(transpose,n);
    return 0;
}
