#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,coef[100],x0,i,pol=0,x=1;
    printf("introduce the number of coefficients:");
    scanf("%d",&n);
    printf("introduce the coefficients:");
    for(i=0; i<n; i++)
        scanf("%d",&coef[i]);
    printf("introduce x0:");
    scanf("%d",&x0);
    for(i=0; i<n; i++)
    {
        pol=pol+coef[i]*x;
        x=x0*x;
    }
    printf("\nthe polinome is: %d",pol);
    return 0;
}
