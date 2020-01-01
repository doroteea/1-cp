#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readCoefficients(int a[100],int n)
{
    for(int i=0;i<=n;i++)
    {
        printf("Please insert the coefficient:\na[%d]=",i);
        scanf("%d",&a[i]);
    }
}
void computePolynomial(int n,int a[100],int x)
{
    int P=0;
    for(int i=0; i<=n; i++)
    {
        P=P+a[i]*pow(x,i);
    }
    printf("P(%d)=%d",x,P);
}
