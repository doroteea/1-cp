#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    int n, m, i, k;
    printf ("n = "); scanf ("%d", &n);
    float *a = (float*)malloc(sizeof (float) * n);
    for (i = 0; i < n; i++)
    {
        scanf ("%f", &a[i]);
    }
    printf ("m = "); scanf ("%d", &m);
    float *b = (float*)malloc(sizeof (float) * m);
    for (i = 0; i < m; i++)
    {
        scanf ("%f", &b[i]);
    }
    float *c = (float*)malloc(sizeof (float) * (n + m));
    c = merging (a, b, n, m, &k);
    for (i = 0; i < k; i++)
    {
        printf ("%f ", c[i]);
    }

    return 0;
}
