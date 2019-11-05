#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s=0,c;
    printf("introduce the number ");
    scanf("%d",&n);
    while(n>0)
    {
        c=n%10;
        s=s+c;
        n=n/10;
    }
    printf("The sum of the digits of the number is %d",s);


    return 0;
}
