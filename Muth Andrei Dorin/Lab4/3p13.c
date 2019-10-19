#include <stdio.h>
#include <stdlib.h>

int cautare (float v[105], float x, int st, int dr)
{
    if (st > dr)
    {
        return 0;
    }
    int mij = (st + dr) / 2;
    if (x == v[mij])
    {
        return mij;
    }
    if (x < v[mij])
    {
        return cautare (v, x, st, mij - 1);
    }
    return cautare (v, x, mij + 1, dr);
}

int main ()
{
    int n, i, gasit;
    float v[105], x;

    scanf ("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf ("%f", &v[i]);
    }
    scanf ("%f", &x);
    gasit = cautare (v, x, 1, n);
    if (gasit != 0)
    {
        printf ("%f in position %d", x, gasit);
    }
    else
    {
        printf ("not found");
    }

    return 0;
}
