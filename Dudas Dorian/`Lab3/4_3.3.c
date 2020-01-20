#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n,elem,max    ,min,i,imax,imin;
    scanf("%f",&n);
    for(i=0; i<n; i++)
    {
        scanf("%f",&elem);
        if(i==0)
        {
            max=elem;
            imax=i;
            min=elem;
            imin=i;
        }
        if(elem>max)
        {
            max=elem;
            imax=i;
        }
        if(elem<min)
        {
            min=elem;
            imin=i;
        }
    }
    printf("Valoarea maxima e:%f, cu indicele:%f\n",max,imax);
    printf("Valoarea minima e:%f, cu indicele:%f",min,imin);
    return 0;
}
