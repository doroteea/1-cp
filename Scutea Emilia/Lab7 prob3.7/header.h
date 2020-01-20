#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * readPolynomial(int size)
{
    int * array=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<=size;i++)
    {
        printf("Please insert the coefficient of the power %d: ",i);
        scanf("%d",(array+i));
    }
    return array;
}
void printPolynomial(int * array,int size)
{
    printf("The polynomial is: ");
    for(int i=0;i<=size;i++)
    {
        if(i!=size)
        {
            printf("%d*x^%d + ",*(array+i),i);
        }
        else
        {
            printf("%d*x^%d.",*(array+i),i);
        }

    }
    printf("\n");
}

int computeValueOfDerivative(int * array,int size,int x)
{
    int P=0;
    for(int i=0;i<=size;i++)
    {
        P += i * *(array+i) * pow(x,i-1);
    }
    return P;
}
