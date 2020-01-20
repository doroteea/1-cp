#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,sir[100],minim,maxim,imin,imax;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&sir[i]);
    }
    minim = sir[0];
    imin = 0;
    maxim = sir[0];
    imin = 0;
    for(i=1;i<n;i++)
    {
        if(sir[i] < minim)
        {
            minim = sir[i];
            imin = i;
        }
        if(sir[i] > maxim)
        {
            maxim = sir[i];
            imax = i;
        }
    }
    printf("%d %d\n",minim, imin);
    printf("%d %d",maxim, imax);
    return 0;
}
