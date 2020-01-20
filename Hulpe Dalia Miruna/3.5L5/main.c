#include <stdio.h>
#include <stdlib.h>

void Addition(int**A,int**B,int n,int**S)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            S[i][j]=A[i][j]+B[i][j];


        }

    }
}
void Subtrastion(int**A,int**B,int n,int**S)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            S[i][j]=A[i][j]-B[i][j];


        }

    }
}
void Multiplication(int**A,int**B,int n,int**S)
{
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            S[i][j]=0;
            for(k=0; k<n; k++)
                S[i][j]=S[i][j]+A[i][k]*B[k][j];
        }
    }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int**B=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        B[i]=(int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    printf("\n");
    int**C=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        C[i]=(int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&C[i][j]);
        }
    }
    int**BC=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        BC[i]=(int*)malloc(n*sizeof(int));
    int**BplusC=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        BplusC[i]=(int*)malloc(n*sizeof(int));
    Multiplication(B,C,n,BC);
    Addition(B,C,n,BplusC);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            BplusC[i][j]*=2;
        }
    }
    int**A=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        A[i]=(int*)malloc(n*sizeof(int));
    Subtrastion(BC,BplusC,n,A);
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
