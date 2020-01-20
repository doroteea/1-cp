#include <stdio.h>
#include <stdlib.h>

int prime(int n)
{
   int d;
   if(n<2)
   {
       return 0;
   }
   if(n%2==0 && n!=2)
   {
       return 0;
   }
   for(d=3;d*d<=n;d+=2)
   {
       if(n%d==0)
       {
           return 0;
       }
   }
   return 1;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        if(prime(i)==1)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
