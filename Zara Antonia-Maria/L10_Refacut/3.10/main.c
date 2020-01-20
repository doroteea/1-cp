/**3.10.A sparse polynomial is a polynomial whose number of zero monomials
        is higher than the one of non-zero monomials.
        Write a program which stores a sparse polynomial of degree m,
        displays that polynomial, and finds its value for a given variable value. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int power;
    float coefficient;
}degreeType;

int readPolynomial(degreeType *polynomial, int m)
{

    int i=0;

    printf("Input the powers with coefficients different from 0 with a space in between:\n");

    int ok = 0;

    while(ok == 0)
    {
        scanf("%d %f",&polynomial[i].power,&polynomial[i].coefficient);
        i++;

        if(polynomial[i-1].power == m)
        {
            ok = 1;
            i--;
        }
    }

    return i;
}

void printPolynomial(degreeType *polynomial, int m)
{
    printf("\nThe polynomial is: ");

    int i;
    for(i=0; i<m; i++)
    {
        printf("(%0.2f)*x^%d + ",polynomial[i].coefficient,polynomial[i].power);
    }
    printf("(%0.2f)*x^%d\n",polynomial[m].coefficient,polynomial[m].power);
}

void calculatePolynomial(int m, degreeType *polynomial, int x)
{
    float answer = 0;
    int xth = 1, i, currentPosition = 0;

    int maxPower = polynomial[m].power;
    for(i=0; i<=maxPower; i++)
    {
        if(polynomial[currentPosition].power == i)
        {
            answer = answer + xth * polynomial[currentPosition].coefficient;
            currentPosition++;
        }
        xth = xth * x;
    }

    printf("\nAnswer is: %f",answer);

}

int main()
{
    int m;
    printf("What's the biggest degree of the polynomial that has a non-zero coefficient?");
    scanf("%d",&m);

    degreeType *polynomial = (degreeType*)malloc(sizeof(degreeType)*m);

    m = readPolynomial(polynomial,m);

    printPolynomial(polynomial,m);

    int x;
    printf("Input value of x: ");
    scanf("%d",&x);

    calculatePolynomial(m,polynomial,x);

    return 0;
}
