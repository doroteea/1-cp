#include <stdio.h>
#include <limits.h>

int main() {

    int i,SequenceLength,ReadNumber,MinimalValue,MaximalValue;
    printf("Enter the length of the sequence:\n");
    scanf ("%d",&SequenceLength);
    MinimalValue=INT_MAX;
    MaximalValue=INT_MIN;
    for (i=0;i<SequenceLength;++i)
    {
        printf("Enter your number:");
        scanf("%d",&ReadNumber);

        if (MinimalValue>ReadNumber)
        {
            MinimalValue=ReadNumber;
        }
        if (MaximalValue<ReadNumber)
        {
            MaximalValue=ReadNumber;
        }

    }
    printf("Your minimal value is %d and your maximal value is %d",MinimalValue,MaximalValue);

    return 0;
}