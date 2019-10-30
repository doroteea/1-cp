#include <stdlib.h>
float* merging (float *a, float *b, int n, int m, int *k)
{
     int i = 0, j = 0;
     *k = 0;
     float *c = (float*)malloc(sizeof (float) * (n + m));
     while (i < n && j < m)
     {
         if (a[i] == b[j])
         {
             i++; j++;
         }
         else
         {
             if (a[i] < b[j])
             {
                 c[*k] = a[i];
                 i++;
                 *k += 1;
             }
             else
             {
                 c[*k] = b[j];
                 j++;
                 *k += 1;
             }
         }
     }
     while (i < n)
     {
         c[*k] = a[i];
         i++;
         *k += 1;
     }
     while (j < m)
     {
         c[*k] = b[j];
         j++;
         (*k)++;
     }
     return c;
}
