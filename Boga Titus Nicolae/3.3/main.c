#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n,IndexMin,IndexMax;
    float Minim=10000,Maxim=-2389328,NrCitit;
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
    printf("Cel mai mare este %f cu indicele %d iar cel mai mic este %f cu indicele %d",Maxim,IndexMax,Minim,IndexMin);
    return 0;
}
