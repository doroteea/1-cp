#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,min,max,nr,i_max,i_min,i,aux;
    scanf("%d %d %d",&n,&min,&max);
    printf("min: %d, max: %d, n: %d", min, max, n);
    i_min=1;
    i_max=2;

    if(min>max)
    {
        aux=min;
        min=max;
        max=aux;
        aux=i_min;
        i_min=i_max;
        i_max=aux;
    }
    for(i=3; i<=n; i++)
    {
        scanf("%d",&nr);
        if(nr>max)
        {
            max=nr;
            i_max=i;
        }
        if(nr<min)
        {
            min=nr;
            i_min=i;
        }
    }
    printf("valoarea minima este %d la pozitia %d, iar valoarea maxima este %d la pozitia %d ",min,i_min,max,i_max);
    return 0;

}
