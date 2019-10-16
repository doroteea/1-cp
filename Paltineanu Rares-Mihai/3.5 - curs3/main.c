/*Read from the standard inputa natural number,n.
Find the greatest perfect square that is less than or equal ton.
Then find the least prime number that is greater than or equal ton.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n, find = 0;
    scanf("%d", &n);
    for(int i = n; i >= 1 && !find; i--)
    {
        if(floor(sqrt(i)) * floor(sqrt(i)) == i)
            {
                find = i;
            }
    }
    printf("%d", find);
    return 0;
}
