#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int SeqSize, i, minPos, maxPos;
    float max, min;
    printf("\nPlease input the size of the sequence of numbers: ");   scanf("%d", &SeqSize);
    printf("\nPlease input the numbers: ");
    float var[SeqSize];
    for(i=0; i<SeqSize; i++)
    {
        scanf("%f", &var[i]);
    }
    for(i=0; i<SeqSize; i++)
    {
        if(var[i]<=var[i+1])
        {
            min=var[i];
            minPos=i;

        }
        else
        {
            max=var[i];
            maxPos=i;
        }
        printf("\n The minimum value is: %.2f", min);
        printf("\n Its position is: %d", minPos);
        printf("\n The maximum value is: %.2f", max);
        printf("\n Its position is: %d", maxPos);
    }
    return 0;
}
