#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x,ElAuxiliar;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&ElAuxiliar);
        if(ElAuxiliar==x)
        {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
