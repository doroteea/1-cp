#include <stdio.h>
#include <stdlib.h>

void print(int **a,int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
}

void power(int **a,int n,int p)
{

    int i,j,k,q;
    int** b=(int**)(malloc(sizeof(int*)*n));
    for(i=0; i<n; i++)
        b[i]=(int*)(malloc(sizeof(int*)*n));
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            b[i][j]=a[i][j];

    int** c=(int**)(malloc(sizeof(int*)*n));
    for(i=0; i<n; i++)
        c[i]=(int*)(malloc(sizeof(int*)*n));
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            c[i][j]=0;

    for(q=0; q<p-1; q++)
    {
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                c[i][j]=0;
                for(k=0; k<n; k++)
                    c[i][j] = c[i][j]+b[i][k]*a[k][j];
            }
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                b[i][j]=c[i][j];
    }

    printf("The matrix at power %d is:\n", p);
    print(b,n);
}

int main()
{
    int n,i,j,p;
    printf("n=");
    scanf("%d",&n);
    int** a=(int**)(malloc(sizeof(int*)*n));
    for(i=0; i<n; i++)
        a[i]=(int*)(malloc(sizeof(int*)*n));
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf("mat[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    print(a,n);
    printf("p=");
    scanf("%d",&p);

    power(a,n,p);

    return 0;
}
