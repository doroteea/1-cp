#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i;
    printf("Choose a number");
    scanf("%d",&x);
    for(i=1; i<x; i++)
        if(x%i==0)
        {
            printf("%d\n",i);
            printf(" ");

        }
    return 0;
}
