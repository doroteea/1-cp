#include <stdio.h>
#include <stdlib.h>

int **mat,**prod;

void readTheMatrix(int **mat,int **prod,int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("mat[%d][%d]=",i,j);
            scanf("%d",&mat[i][j]);

        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("prod[%d][%d]=",i,j);
            scanf("%d",&prod[i][j]);
        }
    }
}

void product(int **mat,int **prod,int n,int k)
{
   int e=1;
   while(e<=k)
   {
       e++;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               prod[i][j]=0;
               //for(int t=0;t<n;t++)

                   prod[i][j]=prod[i][j]+mat[i][j]*mat[j][i];

           }
       }
   }
}

void printTheMatrix(int **prod,int n)
{
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d   ",prod[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n,k;
    printf("Input the number of columns and rows:\n");
    scanf("%d",&n);

    printf("Input the power of the matrix:\n");
    scanf("%d",&k);

    int **mat=(int**)malloc(sizeof(int*)*n);
    int **prod=(int**)malloc(sizeof(int*)*n);

    for(int i=0; i<n; i++)
    {
        mat[i]=(int*)malloc(sizeof(int*)*n);
    }

    for(int j=0;j<n;j++)
    {
        prod[j]=(int*)malloc(sizeof(int*)*n);
    }

    readTheMatrix(mat,prod,n);
    product(mat,prod,n,k);
    printTheMatrix(prod,n);

}
