#include <stdio.h>
#include <stdlib.h>

int* computingPolynomials (int *p, int *q, int n, int m)
{
    int i, j, *r;
    r = (int*)malloc(sizeof (int) * (m + n + 1));
    for (i = 0; i <= m + n; i++)
    {
        r[i] = 0;
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            r[i + j] += p[i] * q[j];
        }
    }
    return r;
}

int main()
{
    int i, *p, *q, m, n, *r;
    printf ("order of p = ");
    scanf ("%d", &n);
    p = (int*)malloc(sizeof (int) * (n + 1));
    for (i = 0; i <= n; i++)
    {
        printf ("p%d = ", i);
        scanf ("%d", &p[i]);
    }
    printf ("order of q = ");
    scanf ("%d", &m);
    q = (int*)malloc(sizeof (int) * (m + 1));
    for (i = 0; i <= m; i++)
    {
        printf ("q%d = ", i);
        scanf ("%d", &q[i]);
    }
    r = computingPolynomials (p, q, n, m);
    printf ("r = p * q = ");
    for (i = 0; i <= m + n; i++)
    {
        printf ("%d * (x ^ %d) ", r[i], i);
        if (i != m + n)
        {
            printf (" + ");
        }
    }
    return 0;
}
