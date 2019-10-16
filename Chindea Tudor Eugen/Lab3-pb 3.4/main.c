#include <stdio.h>
#include <stdlib.h>
int nrprim(int x)
{
    int diviz=2;
    while(diviz*diviz<=x)
    {
        if(x%diviz==0)
            return 0;
        diviz++;
    }
    return 1;
}
int main()
{
    int n,i,diviz;
    scanf("%d",&n);
    printf("numerele urmatoare sunt prime= ");
    for(i=1; i<=n; i++)
    {
        if(nrprim(i))
        {
            printf("%d  ",i);
        }
    }
    return 0;
}
