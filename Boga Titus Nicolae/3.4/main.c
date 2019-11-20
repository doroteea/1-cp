#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int v[10000];
    for(int i=2;i<=n;++i)
    {
        if(!v[i])
        {
            printf("%d ",i);
            for(int j=1;j*i<=n;j++)
                v[j*i]=1;
        }
    }
    return 0;
}
