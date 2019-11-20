#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x, Min, Max, MinPosition, MaxPosition;

    scanf("%d", &x);
    Max=Min=x;
    MaxPosition=MinPosition=1;

    for (int i=2; i<=n; i++)
    {
        scanf("%d", &x);
        if (x>Max)
        {
            Max=x;
            MaxPosition=i;
        }
        if (x<Min)
        {
            Min=x;
            MinPosition=i;
        }
    }

    printf("The minimum value is: %d, on position: %d", Min, MinPosition);
    printf("\nThe maximum value is: %d, on position: %d", Max, MaxPosition);
    return 0;
}
