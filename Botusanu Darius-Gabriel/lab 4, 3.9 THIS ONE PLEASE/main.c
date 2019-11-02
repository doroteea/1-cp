#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

/*I can not understand the "expected ) bevore [" on line 27 or 28*/
int max(a,b)
{
    int c;
    if(a>=b){
        c=a;
    }
    else{
        c=b;
    }
    return c;
}
int min(a,b)
{
    int c;
    if(a>=b){
        c=b;
    }
    else{
        c=a;
    }
    return c;
}

void addition(degA, degB, coeffA[SIZE], coeffB[SIZE])
{
    int i, aux;
    float sum[SIZE];
    for(i=0;i<min(degA,degB);i++)
    {
        sum[i]=coeffA[i]+coeffB[i];
    }
    for(i=min(degA,degB);i<=max(degA,degB);i++)
    {
        if(degA>=degB)
        {
            sum[i]=coeffA[i];
        }
        else
        {
            sum[i]=coeffB[i];
        }
    }
    for(i=0;i<=max(degA,degB);i++)
    {
        printf("\nsum[%d]=%f",i,sum[i]);
    }

}

int main()
{
    int degA, degB, i, j;
    printf("Input the degree of polynomial A: ");
    scanf("%d", &degA);
    float coeffA[degA];
    float coeffB[degB];
    for(i=0;i<=degA;i++)
    {
        printf("\ncoeffA[%d]=",i);
        scanf("%f",&coeffA[i]);
    }
    printf("\nInput the degree of polynomial B: ");
    scanf("%d", &degB);
    for(j=0;j<=degB;j++)
    {
        printf("\ncoeffB[%d]=",j);
        scanf("%f",&coeffB[j]);
    }
    addition(degA, degB, coeffA[SIZE], coeffB[SIZE]);
    return 0;

}
