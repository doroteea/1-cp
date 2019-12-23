/// 3.4.Write a program to compute the value of a polynomial of
///     degree n with complex coefficients for a given complex value.
///     Use functions to implement computations.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int real;
    int imaginary;
} coefficientType;

coefficientType *readPolynomial(int degree)
{
    coefficientType *coefficient = (coefficientType*)malloc(sizeof(coefficientType)*(degree+1));
    int i;
    for(i=degree; i>=0; i--)
    {
        printf("Real part of the coefficient of power %d: ",i);
        scanf("%d",&coefficient[i].real);
        printf("Imaginary part of the coefficient of power %d: ",i);
        scanf("%d",&coefficient[i].imaginary);
    }

    return coefficient;
}

void calculateResult(int degree, coefficientType *coefficient, int x)
{
    coefficientType *result = (coefficientType*)malloc(sizeof(coefficientType)*1);
    result->imaginary=0;
    result->real=0;

    int i,xth=1;
    for(i=0; i<= degree; i++)
    {
        result->real = result->real + coefficient[i].real*xth;
        result->imaginary = result->imaginary + coefficient[i].imaginary*xth;
        xth = xth*x;

    }

    printf("The real part of result is: %d\nThe imaginary part of result is: %d",result->real,result->imaginary);
}

int main()
{
    int degree;
    printf("Input the degree of the polynomial: ");
    scanf("%d",&degree);

    coefficientType *coefficient = (coefficientType*)malloc(sizeof(coefficientType)*(degree+1));
    coefficient = readPolynomial(degree);

    int x;
    printf("Input the value of x: ");
    scanf("%d",&x);

    calculateResult(degree,coefficient,x);


    return 0;
}
