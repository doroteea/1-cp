#include <stdio.h>
#include <stdlib.h>

int main()
{
    float v[100],min=32000,max=-32000,nr;
    int n,pozmin,pozmax,pozact=0,i;
    printf("introduce the sequence length:");
    scanf("%d",&n);
    printf("introduce the sequence numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%f",&nr);
        if(nr<min)
        {
            min=nr;
            pozmin=pozact;
        }
        if(nr>max)
        {
            max=nr;
            pozmax=pozact;
        }
        pozact++;
    }
    printf("the minimum is %f ,and was found on pozition %d",min,pozmin);
    printf("\nthe maximum is %f ,and was found on pozition %d",max,pozmax);
    return 0;
}
