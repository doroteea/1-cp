#include <stdio.h>
#include <stdlib.h>

int main()
{
    //NU AM INTELES CERINTA
    int n,a[200],b[200],c[200];
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    printf("P(x)=");
    for(int i=1;i<=n;++i)
    {
        if(i!=1)
        {
            printf("*");
        }
        printf("(%dX + %d)",b[i],c[i]);

    }

    printf("\nQ(x)=");
    for(int i=1;i<=n;++i)
    {
        if(i!=1)
        {
            printf("+");
        }
        printf(" %d",a[i]);
        for(int j=1;j<=n;++j)
            if(j!=i)
            {
                printf("*(%dX + %d)",b[j],c[j]);

            }
    }


    return 0;
}
