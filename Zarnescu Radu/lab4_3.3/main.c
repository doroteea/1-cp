#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    float n,x,maxValue,minValue;
    int i;
    scanf("%f",&n);
    scanf("%f",&x);
    maxValue=x;
    minValue=x;
    for(i=2; i<=n; i++)
    {
        scanf("%f",&x);
        if(x>maxValue)
        {
            maxValue=x;
        }
        if(x<minValue)
        {
            minValue=x;
        }
    }
    printf("maximum value is:%f",maxValue);
    printf("\nminimum value is:%f",minValue);



    return 0;
}
