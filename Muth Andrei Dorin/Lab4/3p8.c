#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int i, x0, n, a[105], r;
    printf ("the degree of p is n=");
    scanf ("%d", &n);
    printf ("the coefficients of p are:\n");
    for (i = 0; i <= n; i++)
    {
        printf ("a%d=", i);
        scanf ("%d", &a[i]);
    }

    printf ("the polinomyal is:\np(x) = ");
    for (i = 0; i <= n; i++)
    {
        printf ("%d * (x ^ %d)", a[i], i);
        if (i < n)
        {
            printf (" + ");
        }
    }

    printf ("\ngive a value for x0: ");
    scanf ("%d", &x0);
    r = 0;
    for (i = 0; i <= n; i++)
    {
        r = r + a[i] * pow (x0, i);
    }
    printf ("p(%d) = %d", x0, r);
    return 0;
}
