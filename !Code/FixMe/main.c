#include <stdio.h>
#include <stdlib.h>

void print(int **a,int n,int m)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf(" %d ",&a[i][j]);
        }
        printf("\n");
    }
}

void transpose(int **a,int n,int m)
{
    int i,j;
    int** b=(int**)(malloc(sizeof(int*)*m));
    for(i=0; i<m; i++)
        b[i]=(int*)(malloc(sizeof(int*)*n));
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            b[j][i]=a[i][j];
    print(b,m,n);
}

int main()
{
    int n,i,j,m;
    printf("n=");
    scanf("%d",n);
    printf("m=");
    scanf("%d",m);
    int** a=(int**)(malloc(sizeof(int*)*n));
    for(i=0; i<n; i++)
        a[i]=(int*)(malloc(sizeof(int*)*m));
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            printf("mat[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    print(&a,&n,&m);
    transpose(a,n,m);
    return 0;
}
