#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{
    int SeqSize,i,minPos,maxPos;
    float number,MaxValue,MinValue;
    scanf("%d",&SeqSize);
    MaxValue=FLT_MIN;
    MinValue=FLT_MAX;
    for(i=0;i<SeqSize;i++)
    {
        scanf("%f",&number);
        if(number>MaxValue)
        {
            MaxValue=number;
            maxPos=i;
        }
        if(number<MinValue)
        {
            MinValue=number;
            minPos=i;
        }
    }
    printf("Minim value is: %.2f and min pos is: %d \n",MinValue,minPos);
    printf("Max value is: %.2f and max pos is: %d \n",MaxValue,maxPos);
    return 0;
}
