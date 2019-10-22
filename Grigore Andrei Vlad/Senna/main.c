#include <stdio.h>
#include <stdlib.h>

int main()
{int n,i,aux,x;
scanf("%d %d",&n,&x);
for(i=1;i<=n;i++)
{
    scanf("%d",&aux);
    if(aux==x)
    {
            printf("The number and position are:%d %d",x,i);
    }


}
    return 0;
}
