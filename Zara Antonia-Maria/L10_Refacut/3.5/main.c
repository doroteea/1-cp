/// 3.5.Construct a new type, rational type, as a structure composed of a numerator (integer)
///     and a denominator (integer), used to represent fractions.
///     Write functions to perform the operations: simplification, addition, subtraction, division, power for this type.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int denominator;
    int numerator;
} fractionType;

fractionType *readFraction(int i)
{
    fractionType *number = (fractionType*)malloc(sizeof(fractionType));
    printf("Input the denominator of fraction nr. %d: ",i);
    scanf("%d",&number->denominator);
    printf("Input the numerator of fraction nr. %d: ",i);
    scanf("%d",&number->numerator);

    return number;
}

int findCMMDC(int a, int b)
{
    /// aflam cel mai mare divizor comun cu algoritmul lui
    /// Euclid pe care il stiu pe derost cu a si b ca variabile
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

fractionType *simplification(fractionType *number)
{
    int cmmdc = findCMMDC(number->numerator,number->denominator);
    number->denominator = number->denominator/cmmdc;
    number->numerator = number->numerator/cmmdc;

    return number;

}

void addition(fractionType *nr1, fractionType *nr2)
{
    int cmmdc = findCMMDC(nr1->denominator,nr2->denominator);
    int cmmmc = (nr1->denominator * nr2->denominator) / cmmdc;

    fractionType *result = (fractionType*)malloc(sizeof(fractionType));

    result->denominator = cmmmc;
    result->numerator = (nr1->numerator * (cmmmc / nr1->denominator)) + (nr2->numerator * (cmmmc / nr2->denominator));

    printf("%d/%d",result->numerator,result->denominator);
}

void substraction(fractionType *nr1, fractionType *nr2)
{
    nr2->denominator = nr2->denominator * (-1);
    addition(nr1,nr2);
}

void division(fractionType *nr1, fractionType *nr2)
{
    fractionType *result = (fractionType*)malloc(sizeof(fractionType));

    int aux;
    aux = nr2->denominator;
    nr2->denominator = nr2->numerator;
    nr2->numerator = aux;

    nr2->denominator = nr2->denominator * (-1);

    result->numerator = nr1->numerator * nr2->numerator;
    result->denominator = nr1->denominator * nr2->denominator;

    result = simplification(result);

    printf("\nResult of division is: %d/%d",result->numerator,result->denominator);
}

void power(fractionType *nr, int nrpow)
{
    fractionType *result = (fractionType*)malloc(sizeof(fractionType));

    nr = simplification(nr);

    int i;
    int initialDenominator = nr->denominator;
    int initialNumerator = nr->numerator;
    result->denominator = 1;
    result->numerator = 1;
    for(i=1; i<=nrpow; i++)
    {
        result->denominator = result->denominator * initialDenominator;
        result->numerator = result->numerator * initialNumerator;
    }

    printf("\nResult of power is: %d/%d",result->numerator, result->denominator);
}

int main()
{
    fractionType *number1 = (fractionType*)malloc(sizeof(fractionType));
    fractionType *number2 = (fractionType*)malloc(sizeof(fractionType));

    number1 = readFraction(1);
    number2 = readFraction(2);

    int nrpow;
    printf("Input nr of power: ");
    scanf("%d",&nrpow);

    number1 = simplification(number1);
    number2 = simplification(number2);

    printf("\nResult of addition is: ");
    addition(number1, number2);
    printf("\nResult of substraction is: ");
    substraction(number1, number2);
    division(number1, number2);
    power(number1,nrpow);

    return 0;
}
