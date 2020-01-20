/*Real numbers of a sequence of size n are read from the standard input.
Find and print to standard output:the minimum and the maximum valuesof this sequence,
and their positions(indices)in the sequence.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    double n, pos, minim, maxim, a;
    scanf("%lf", &n);
    minim = INT_MAX/2;
    maxim = INT_MIN/2;
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &a);
        maxim = a > maxim ? a: maxim;
        minim = a < minim ? a: minim;
    }

    printf("%lf", minim);
    printf("\n%lf", maxim);


    return 0;
}
