#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,div,nr,prim;
    scanf("%d",&n);
    for(nr=2;nr<=n;nr++)
    {   prim=1;
        for(div=2;div<=nr-1;div++)
        {
            if(nr%div==0)
            {
            prim=0;
            break;
            }
        }
        if(prim==1)
            printf("%d, ",nr);
    }
    return 0;

}
