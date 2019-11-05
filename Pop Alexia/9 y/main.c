#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b,c,max;
    printf("Input the first integer\n");
    scanf("%d",&a);
    printf("Input the second integer\n");
    scanf("%d",&b);
    printf("Input the third integer \n");
    scanf("%d",&c);
    if (a>b)
    {
        max=a;

    }
    else
    {
        max=b;
    }
    if(max>c)
    {
        printf("The maximum value of the three integers is %d",max);

    }
    else
    {
        max=c;
        printf("The maximum value of the three integers is %d",max);

    }







    return 0;
}
