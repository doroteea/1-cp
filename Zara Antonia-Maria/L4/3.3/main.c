#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n,x,max,min,PosMax=1,PosMin=1;
    int i;
    scanf("%f",&n);
    scanf("%f",&x);
    min=x;
    max=x;
    for(i=2;i<=n;i++)
    {
        scanf("%f",&x);
        if(x>max)
        {
            max=x;
            PosMax=i;
        }
        if(x<min)
        {
            min=x;
            PosMin=i;
        }
    }
    printf("The max number is %f on the position %f",max,PosMax);
    printf("\nThe min number is %f on the position %f",min,PosMin);
    return 0;
}
