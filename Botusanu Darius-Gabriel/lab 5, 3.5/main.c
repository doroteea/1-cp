#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
int **mat=(int*)malloc(sizeof(int*)*rows)
int multiply(int n, float b[n][n], float c[n][n], float p[n][]);
{
    p[][]=b[][]*c[];
}
int addition(int n, float b[][], float c[][], float s[][])
{
    s[][]=b[][]+c[][];
}
int substraction(int n, float b[][], float c[][], float d[][])
{
    d[][]=b[][]-c[][];
}
int main()
{

    int i,j,n;
    printf("\nPlease input the size of the square matrices: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("\nb[%d][%d]",i,i);
        scanf("%f", &b[i][i]);
        printf("\n");
        printf("\nc[%d][%d]",i,i);
        scanf("%f", &c[i][i]);
    }
    multiply(*n,b[][],c[][],p[][]);
    addition(*n,b[][],c[][],s[][]);
    float a[][];
    for(i=0;i<=n:i++)
    {
        a[i][i]=substraction(n,p[][],2*s[]);
        printf("%f",a[i][i]);
    }
    return 0;
}
