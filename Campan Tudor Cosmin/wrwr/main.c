#include <stdio.h>
#include <stdlib.h>
#include <float.h>
int main()
{
    int n,i,pozMin=0,pozMax=0;
    float nr,min=FLT_MAX,max=FLT_MIN;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%f",&nr);
        if(nr>max)
        {
            max=nr;
            pozMax=i;
        }
        if(nr<min)
        {
            min=nr;
            pozMin=i;
        }
    }
    printf("cel mai mic numar este %.2f pe pozitia %d iar cel mai mare este %.2f pe pozitia %d",min,pozMin,max,pozMax);

    return 0;
}
