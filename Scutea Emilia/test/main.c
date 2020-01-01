#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],i,ok,aux;
    for(i=0; i<10; i++)
    {
        printf("Introduce the number:");
        scanf("%d",&a[i]);
    }
    ok=0;
    while(ok==0)
    {
        ok=1;
        for(i=0; i<9; i++)
            if(a[i]>a[i+1])
            {
                aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
                ok=0;
            }
    }
    printf("The elements are:\n");
    for(i=0;i<10;i++)
    {
        printf("%d   ",a[i]);
    }
    return 0;
}
