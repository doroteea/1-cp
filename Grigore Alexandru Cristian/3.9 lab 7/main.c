#include <stdio.h>
#include <stdlib.h>
int** multiplication(int **A,int **B,int n)
{
    int i,j,sum,l;
    int **M=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        M[i]=(int*)malloc(sizeof(int)*n);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            sum=0;
            for(l=0; l<n; l++)
            {
                sum=sum+A[i][l]*B[l][j];
                M[i][j]=sum;
            }
        }

    }
    return M;
}
int** Power(int **A,int n,int k)
{
    int i,j;
    int **B=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        B[i]=(int*)malloc(sizeof(int)*n);
    }
    if(k==0)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j)
                {
                    B[i][j]=1;
                }
                else
                {
                    B[i][j]=0;
                }
            }
        }
        return B;
    }
    B=A;
    for(i=1; i<k; i++)
    {
        A=multiplication(A,B,n);
    }
    return A;


}
int main()
{
    int n,i,j,k,**A;
    scanf("%d",&n);
    **A=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        A[i]=(int*)malloc(sizeof(int)*n);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("enter power");
    scanf("%d",&k);
    A=Power(A,n,k);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
