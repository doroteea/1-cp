#include <stdio.h>
#include <stdlib.h>

int main()
{
    int degree, i;
    printf("Please input the degree of your polynomial: ");
    scanf("%d", &degree);
    double coefficients[degree];
    for(i=0;i<=degree;i++)
    {
        printf("\na[%d]=",i);
        scanf("%lf",&coefficients[i]);
    }
    printf("\nThese are the coefficients of your polynomial: ");
    for(i=0;i<=degree;i++)
    {
        printf("\na[%d]=%2.f",i,coefficients[i]);
    }
    return 0;
}
