
#include <stdio.h>
#include <stdlib.h>
int readBaseb2(int b2)
{
    printf("Please input the base in which you want to convert:\nb2=");
    scanf("%d",&b2);
    while(b2<2 || b2>16)
    {
        printf("The base is incorrect. Please input another value:\nb2=");
        scanf("%d",&b2);
    }
    return b2;
}

void printInBase(int x, int y)
{
   if ( x < y )
   {
      printf("%d",x);
      return;
   }

   int rem = x%y;
   printInBase(x/y, y);
   printf("%d",rem);
}
