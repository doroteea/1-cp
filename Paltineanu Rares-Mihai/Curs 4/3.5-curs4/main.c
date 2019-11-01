/**
Read from the standard inputa natural number,n.
Find the greatest perfect square that is less than or equal ton.
Then find the least prime number that is greater than or equal ton.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, find = 0, prim, done = 0;
    scanf("%d", &n);
    for(int i = n; i >= 1 && !find; i--)
    {
        if(floor(sqrt(i)) * floor(sqrt(i)) == i)
            {
                find = i;
            }
    }
    printf("The greatest perfect square that is less than or equal to n is %d.\n", find);
    prim = n;
    while(!done)
    {
        if(prim % 2 == 0){
            prim ++;
        }
        else{
            done = 1;
            for(int j = 3; j <= prim / 2 && done; j+=2)
                if(prim % j == 0)
                    done = 0;
        }
    }
    printf("The least prime number that is greater than or equal to n is %d.", prim);
    return 0;
}
