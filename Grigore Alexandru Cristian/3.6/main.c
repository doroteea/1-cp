#include <stdio.h>
#include <stdlib.h>

int main()
{ int x,rev=0,remain,n;
printf("Enter x:");
scanf("%d",&x);
n=x;
while(x!=0)
{
    remain=x%10;
    rev=rev*10+remain;
    x=x/10;
}
    if(n==rev)
        {
            printf("%d is palindrome",n);
        }
    else
        {
        printf("%d is not palindrome",n);
        }
    return 0;
}
