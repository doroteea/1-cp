#include <stdio.h>

int main()
{
    int n, i, maxPozition, minPozition;
    float sequence[100], maxValue, minValue;

    scanf("%d",&n);

    for (i=0;i<n;i++)
    {
        scanf("%f", &sequence[i]);
    }
    maxValue=sequence[0];
    minValue=sequence[0];
    maxPozition=0;
    minPozition=0;

    for (i=1;i<n;i++)
    {
        if (sequence[i]>maxValue)
        {
            maxValue=sequence[i];
            maxPozition=i;
        }

        if (sequence[i]<minValue)
        {
            minValue=sequence[i];
            minPozition=i;
        }
    }

    printf("Biggest number: %f\n", maxValue);
    printf("Biggest number's position: %d\n", maxPozition);
    printf("Smallest number: %f\n", minValue);
    printf("Smallest number's position: %d\n", minPozition);

    return 0;
}