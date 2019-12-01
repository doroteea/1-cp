#include <stdio.h>
#include <stdlib.h>

int *readPolynomial(int order)
{
    int i;
    int *coefficients=(int*)malloc(sizeof(int)*order);

    printf("Input the coefficients of x to the power of: ");
    for(i=0; i<=order; i++)
    {
        printf("\n %d -> ",i);
        scanf("%d",&coefficients[i]);
    }

    return coefficients;
}

int decideOrderMax(int order1, int order2)
{
    int order;
    if(order1>order2)
    {
        order = order1;
    }
    else
    {
        order = order2;
    }
    return order;
}

int *notePresenceOfX(int *coefficients, int order)
{
    int i;
    int *presenceOfPowerOfX=(int*)malloc(sizeof(int)*order);
    for(i=0; i<=order; i++)
    {
        if(coefficients[i]!=0)presenceOfPowerOfX[i]=1;
        else presenceOfPowerOfX[i]=0;
    }
    return presenceOfPowerOfX;
}

int *multiplyPolynomials(int *coefficients1, int *coefficients2, int order1, int order2, int orderFinal)
{
    int i,j;

    int *coefficientsFinal=(int*)calloc(orderFinal,sizeof(int));


    for(i=0; i<=order1; i++)
    {
        for(j=0; j<=order2; j++)
        {
            coefficientsFinal[i+j]=coefficientsFinal[i+j]+coefficients1[i]*coefficients2[j];
        }
    }

    return coefficientsFinal;
}

void printPolynomial(int *coefficientsFinal, int *presenceOfPowerOfX, int orderFinal)
{
    int i;
    printf("The product of the two polynomials is: \n");
    for(i=orderFinal; i>=0; i--)
    {
        if(presenceOfPowerOfX[i]!=0)
        {
            printf("%d*x^%d\n",coefficientsFinal[i],i);
        }
    }
}

int main()
{
    int order1,order2;

    printf("Input the order of the first polynomial: ");
    scanf("%d",&order1);

    int *coefficients1=(int*)malloc(sizeof(int)*order1);
    coefficients1 = readPolynomial(order1);

    printf("Input the order of the second polynomial: ");
    scanf("%d",&order2);

    int *coefficients2=(int*)malloc(sizeof(int)*order2);
    coefficients2 = readPolynomial(order2);

    ///notez prezenta fiecarei putere din polinom cu 1 intr-un vector
    ///prezenta in vector va fi notata pana la puterea maxima dintre cele doua polinoame

    int orderMax;
    orderMax = decideOrderMax(order1,order2);

    ///notez prezenta puterilor pentru ca ma va ajuta la afisarea polinomului

    int orderFinal;
    orderFinal=order1+order2;

    int *coefficientsFinal=(int*)calloc(orderFinal,sizeof(int));

    coefficientsFinal = multiplyPolynomials(coefficients1,coefficients2,order1,order2,orderFinal);

    int *presenceOfPowerOfX=(int*)malloc(sizeof(int)*orderMax);
    presenceOfPowerOfX = notePresenceOfX(coefficientsFinal,orderMax);

    printPolynomial(coefficientsFinal,presenceOfPowerOfX,orderFinal);

    return 0;
}
