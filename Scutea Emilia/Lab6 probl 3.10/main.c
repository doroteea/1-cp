#include <stdio.h>
#include <stdlib.h>

void readTheMatrix(int **a,int n)
{
   for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("a[%d][%d]",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void transposedOfMatrix(int **a,int n)
{
    int i,j,aux;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            aux=a[i][j];a[i][j]=a[j][i];a[j][i]=aux;
            i++;
        }
    }
}

void printTheMatrix(int **a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d   ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Input the number of columns and rows:\n");
    scanf("%d",&n);
    int **a=(int**)malloc(sizeof(int*)*n);


    for(int i=0; i<n; i++)
    {
        a[i]=(int*)malloc(sizeof(int*)*n);
    }
    readTheMatrix(a,n);
    printTheMatrix(a,n);
    transposedOfMatrix(a,n);
    printTheMatrix(a,n);
}
