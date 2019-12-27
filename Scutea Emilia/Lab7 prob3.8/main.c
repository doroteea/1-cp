#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int n;
    printf("Please input the order of the polynomial:\nn=");
    scanf("%d",&n);
    int * pol1=readPolynomial(n);
    printf("The first polynomial is: ");
    printPolynomial(pol1,n);

    int m;
    printf("Please input the order of the polynomial:\nm=");
    scanf("%d",&m);
    int * pol2=readPolynomial(m);
    printf("The second polynomial is: ");
    printPolynomial(pol2,m);

    int k=n+m;
    int * pol3=product(pol1,pol2,n,m,k);
    printf("The product of the polynomials is: ");
    printPolynomial(pol3,k);


}
