#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i;
    printf("Give n:");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        if(sqrt(i)*sqrt(i)==i)
        {
            printf("The greatest perfect square less or equal to n is %d",i);
            break;
        }
    }



    return 0;
}
