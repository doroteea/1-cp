#include "header.h"
int main()
{
    int a[100],n;
    int x;
    printf("Please insert the order of the polynomial:\nn=");
    scanf("%d",&n);
    printf("Please input x:\nx=");
    scanf("%d",&x);
    readCoefficients(a,n);
    computePolynomial(n,a,x);
}
