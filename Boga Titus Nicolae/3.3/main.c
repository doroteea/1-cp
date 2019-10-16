#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{

    int n,IndexMin,IndexMax;
    float Minim=FLT_MAX,Maxim=FLT_MIN,NrCitit;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%f",&NrCitit);
        if(NrCitit>Maxim)
        {
            Maxim=NrCitit;
            IndexMax=i;
        }
        if(NrCitit<Minim)
        {
            Minim=NrCitit;
            IndexMin=i;
        }

    }
    printf("Cel mai mare este %.2f cu indicele %d iar cel mai mic este %f cu indicele %d",Maxim,IndexMax,Minim,IndexMin);
    return 0;
}
