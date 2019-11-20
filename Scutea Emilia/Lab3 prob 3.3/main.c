#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a[100],minim=32000,maxim=-32000;
    int n,i,pozmin=0,pozmax=0;
    printf("Give the number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nGive the element:");
        scanf("%f",&a[i]);
        if(a[i]<minim)
        {
            minim=a[i];
            pozmin=i;
        }
        if(a[i]>maxim)
        {
            maxim=a[i];
            pozmax=i;
        }
    }
    printf("The minimum is %f and was found on position %d\n",minim,pozmin);
    printf("The maximum is %f and was found on position %d\n",maxim,pozmax);

    return 0;
}
