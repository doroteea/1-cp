#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, sum=0;
    printf("The first 10 natural numbers are :\n");
    scanf("%d",&i);
    for(i=1; i<=10; i++)
    {
        printf("%i\n",i);
        sum+=i;
    }
    printf("The sum of the 10 natural numebrs is :%d",sum);
    return 0;
}
