#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,PerfectSquare,Prime,Div,ConditionPrime=0,ConditionSquare=0,Ok;
    scanf("%d",&n);
    PerfectSquare=n;
    Prime=n;
    while(ConditionPrime==0||ConditionSquare==0)
    {
        if(ConditionSquare==0)
        {
            Ok=0;
            for(Div=1; Div<=PerfectSquare; Div++)
            {
                if(Div*Div==PerfectSquare)
                {
                    Ok=Div;
                }
            }
            if (Ok==0)
                PerfectSquare--;
            else
            {
                ConditionSquare=1;
            }

        }
        if(ConditionPrime==0)
        {
            Ok=1;
            for(Div=2; Div<=sqrt(Prime)&&Ok==1; Div++)
            {
                if(Prime%Div==0)
                    Ok=0;
            }
            if(Ok==1)
            {
                ConditionPrime=1;
            }
            else
            {
                Prime++;
            }
        }
    }
    printf("prime= %d and perfect square= %d",Prime,PerfectSquare);

    return 0;
}
