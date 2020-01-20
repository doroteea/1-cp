#include <stdio.h>
#include <stdlib.h>

int main()
{
 int num;
 printf("Introduce a number \n");
 scanf("%d",&num);
 if (num%3==0)
    printf("The number is a multiple of 3 ");
 else if (num%7==0)
    printf("The number is a multiple of 7 ");
 else if(num%3!=0|| num%7!=0)
    printf("The number is neither a multiple of 3 nor 7");
    return 0;
}
