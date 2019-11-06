#include <stdio.h>
#include <stdlib.h>

void multiply(float *a,float *b,int n,int m)
{
    int i,j;
    float *c=(int*)(malloc(sizeof(int)*(m+n-1)));
    for(i=0; i<n+m-1; i++)
        c[i]=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            c[i+j]=c[i+j]+a[i]*b[j];
    for(i=0; i<n+m-1; i++)
        printf(" %f * x^%d +",c[i],i);
}
int main()
{
    int n,m,i;
    printf("n= ");
    scanf("%d",&n);
    float *a=(int*)(malloc(sizeof(int)*n));
    printf("input coeffiients: ");
    for(i=0; i<n; i++)
        scanf("%f",&a[i]);

    printf("m= ");
    scanf("%d",&m);
    float *b=(int*)(malloc(sizeof(int)*m));
    printf("input coefficients: ");
    for(i=0; i<m; i++)
        scanf("%f",&b[i]);

    multiply(a,b,n,m);
    return 0;
}
