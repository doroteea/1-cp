#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

int min(int *a, int *b);

int max(int *a, int *b);

void addition(int degA, float coeffA[degA], int degB, float coeffB[degB]);

int main()
{
    int degA, degB, i;
    printf("Please input the degree of polynomial A:");
    scanf("%d", &degA);

    printf("\nPlease input the degree of polynomial B:");
    scanf("%d", &degB);

    float coeffA[degA], coeffB[degB];

    for(i=0; i<=degA; i++)
    {
        printf("\ncoeffA[%d]=",i);
        scanf("%f", &coeffA[i]);
    }

    for(i=0; i<=degB; i++)
    {
        printf("\ncoeffB[%d]=",i);
        scanf("%f", &coeffB[i]);
    }
    addition(int degA, float coeffA[degA], int degB, float coeffB[degB]);

    return 0;

}

void addition(int degA, float coeffA[degA], int degB, float coeffB[degB])
{
    int i;
    float coeffC[SIZE];

    for(i=0; i<min(&degA, &degB); i++)
    {
        coeffC[i]=coeffA[i]+coeffB[i];
    }
    for(i=min(&degA, &degB); i<=max(&degA, &degB); i++)
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
    for(i=0; i<=max(&degA, &degB); i++)
    {
        printf("\ncoeffC[%d]=%f; ", i, coeffC[i]);
    }
}

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
