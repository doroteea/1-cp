///polynomial
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int degree,x0,coefficient,i,power=1,p=0;
    printf("Input the degree: ");
    scanf("%d",&degree);
    printf("Input the value for x0: ");
    scanf("%d",&x0);
    printf("Input the coefficients: ");
    for(i=0;i<=degree;i++)
    {
        scanf("%d",&coefficient);
        p=p+coefficient*power;
        power=power*x0;
    }
    printf("%d",p);
    return 0;
}
