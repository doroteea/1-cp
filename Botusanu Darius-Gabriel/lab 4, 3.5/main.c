#include <stdio.h>
#include <stdlib.h>
/*I haven't got a clue how to do the prime part...*/

int main()
{
    int n,i,j, max=-999999, prime;
    printf("Please input an integer value: \n");    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        j=0;
        while(j<=n)
        {
            j++;
            if(j==i*i)
            {
                if(j>max)
                {
                    max=j;
                }
            }
        }
    }
    printf("The greatest perfect square smaller or equal to %d is: %d", n, max);
    for(i=1; i<n; i++)
    {

    }

    return 0;
}
