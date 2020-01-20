#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int n;
    printf("Please input the order of the polynomial:\nn=");
    scanf("%d",&n);
    int x;
    printf("Please insert the value x:\nx=");
    scanf("%d",&x);
    int * pol=readPolynomial(n);
    printPolynomial(pol,n);
    printf("The value of the derivative of the polynomial is P=%d.",computeValueOfDerivative(pol,n,x));
}
