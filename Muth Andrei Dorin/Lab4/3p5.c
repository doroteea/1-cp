#include <stdio.h>
#include <stdlib.h>

int prim (int x)
{
    if (x == 0 || x == 1)
    {
        return 0;
    }
    int nrd = 0, i;
    for (i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            nrd++;
        }
    }
    return !nrd;
}

int main()
{
    int n, i, x;
    scanf ("%d", &n);
    i = 0;
    while (i * i <= n)
    {
        i++;
    }
    printf ("the greatest perfect square that is less than or equal to %d is %d", n, (i - 1) * (i - 1));
    x = n;
    while (!prim (x))
    {
        x++;
    }
    printf ("\nthe least prime number that is greater than or equal to %d is %d", n, x);
    return 0;
}
