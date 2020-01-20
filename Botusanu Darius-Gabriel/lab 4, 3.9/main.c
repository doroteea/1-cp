#include <stdio.h>
#include <stdlib.h>
#include "header.c"
#define SIZE 200


int main()
{
    int degA, degB, i, int *quotient_deg, float *quotient, int *remainder_deg, float *remainder;
    float *coeffA=(float*)malloc(sizeof(float)*SIZE);
    float *coeffB=(float*)malloc(sizeof(float)*SIZE);
    float *quotient=(float*)malloc(sizeof(float)*SIZE);
    float *remainder=(float*)malloc(sizeof(float)*SIZE);

    printf("Please input the degree of polynomial A:");
    scanf("%d", &degA);
    for(i=0; i<=degA; i++)
    {
        printf("\ncoeffA[%d]=",i);
        scanf("%f", &coeffA[i]);
    }

    printf("\nPlease input the degree of polynomial B:");
    scanf("%d", &degB);
    for(i=0; i<=degB; i++)
    {
        printf("\ncoeffB[%d]=",i);
        scanf("%f", &coeffB[i]);
    }
    printf("\nThese are the coefficients of the sum of A(X) and B(X):");
    addition(degA, coeffA, degB, coeffB);

    printf("\nThese are the coefficients of the difference between A(X) and B(X):");
    substraction(degA, coeffA, degB, coeffB);

    printf("\nThese are the coefficients of the product between A(x) and B(x):\n");
    float product(degA, coeffA, degB, coeffB); /*just a small tip please*/

    printf("\nThese are the coefficients of the division between A(x) and B(x):\n");
    void divide(degA, coeffA, degB, coeffB,
                quotient_deg, quotient,
                remainder_deg, remainder);



    return 0;

}





