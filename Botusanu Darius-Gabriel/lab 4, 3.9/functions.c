#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

int min(int *a, int *b)
{
    int aux;
    if(*a<=*b)
    {
        aux=*a;
    }
    else
    {
        aux=*b;
    }
    return aux;
}

int max(int *a, int *b)
{
    int aux;
    if(*a<=*b)
    {
        aux=*b;
    }
    else
    {
        aux=*a;
    }
    return aux;
}

int ** addition(int degA, float *coeffA, int degB, float *coeffB)
{
    int i;
    float *coeffC=(float*)malloc(sizeof(float)*SIZE);

    for(i=0; i<=min(&degA, &degB); i++)
    {
        coeffC[i]=coeffA[i]+coeffB[i];
    }
    for(i=min(&degA, &degB)+1; i<=max(&degA, &degB); i++)
    {
        if(degA>degB)
        {
            coeffC[i]=coeffA[i];
        }
        else
        {
            coeffC[i]=coeffB[i];
        }
    }
    return coeffC;
}

int ** substraction(int degA, float *coeffA, int degB, float *coeffB)
{
    int i;
    float *coeffC=(float*)malloc(sizeof(float)*SIZE);

    for(i=0; i<=min(&degA, &degB); i++)
    {
        coeffC[i]=coeffA[i]-coeffB[i];
    }
    for(i=min(&degA, &degB)+1; i<=max(&degA, &degB); i++)
    {
        if(degA>degB)
        {
            coeffC[i]=coeffA[i];
        }
        else
        {
            coeffC[i]=(-1)*coeffB[i];
        }
    }
    return coeffC;
}

float ** product(int degA, float *coeffA, int degB, float *coeffB)
{
    int i,j;
    float *product=(float*)malloc(sizeof(float)*SIZE);
    for(i=0; i<=degA*degB; i++)
    {
        product[i]=0;
    }

    for(i=0; i<=max(&degA,&degB); i++)
    {
        for(j=0; j<=min(&degA,&degB); j++)
        {
            (degA>degB)?(product[i+j]+=coeffA[i]*coeffB[j]):(product[i+j]+=coeffA[j]*coeffB[i]);
        }
    }
    return product;
}

void divide(int degA, float *a, int degB, float *b,
            int *quotient_deg, float *quotient,
            int *remainder_deg, float *remainder)
{
    int i, j, k;
    if (degA<degB)
    {
        *quotient_deg=0;
        quotient[0]=0.0;
        *remainder_deg=degB;
        remainder=quotient;
    }
    else
    {
        *quotient_deg=degA-degB;
        *remainder_deg=degB-1;
        for(i=degA-degB, j=degA; i>=0; i--, j--)
        {
            quotient[i]=a[j]/b[degB];
            for (k=degB; k>=0; k--)
                a[i+k]=a[i+k]-quotient[i]*b[k];
            a[j]=0;
        }
        for(i=0; i<=degB-1; i++)
            remainder[i]=a[i];
    }
}
