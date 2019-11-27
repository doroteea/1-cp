#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *readPolynomial(int order)
{
    int i;
    int *coefficients=(int*)malloc(sizeof(int)*order);

    printf("Input the coefficient for x to the power of:\n");
    for(i=order; i>=0; i--)
    {
        printf("%d -> ",i);
        scanf("%d",&coefficients[i]);
    }
    return coefficients;
}

void derivatePolynomial(int *coefficients, int order, int derivative)
{
    int i,j;

    if(derivative>order+1)
        for(i=0; i<=order; i++)coefficients[i]=0;
    ///daca se deriveaza de prea multe ori polinomul devine 0

    else
    {
        for(i=1; i<=derivative; i++)
        {
            for(j=0; j<=order; j++)
            {
                coefficients[j]=coefficients[j+1]*(j+1);
            }
            for(j=1; j<=i; j++)
                coefficients[order-j+1]=0;

        }
    }
}

void calculatePolynomial(int *coefficients,int order, int x)
{
    int i,result=0;
    for(i=0; i<=order; i++)
    {

        int a = pow(x,i);
        result = result + coefficients[i]*a;
    }
    printf("%d",result);
}

int main()
{
    int order,derivative,x;

    printf("Input the order of the polynomial: ");
    scanf("%d",&order);
    int *coefficients=(int*)malloc(sizeof(int)*order);

    coefficients = readPolynomial(order);

    printf("Input the order of the derivative: ");
    scanf("%d",&derivative);

    derivatePolynomial(coefficients,order,derivative);

    printf("Input the point for which you want to calculate the derivative of the polynomial: ");
    scanf("%d",&x);

    calculatePolynomial(coefficients,order,x);

    return 0;
}
