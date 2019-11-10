#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n,SqrtOfPerfectSquare,prime=0,VarHigerThan_n,Div;
int main()
{
    scanf("%d",&n);
    if(n==0)
    {
        printf("no perfect square\n");
        printf("smallest prime number higer than n is 2");
    }
    else
    {
        SqrtOfPerfectSquare=0;
        while(SqrtOfPerfectSquare*SqrtOfPerfectSquare<=n)
        {
            SqrtOfPerfectSquare++;
        }
        SqrtOfPerfectSquare--;
        printf("largest perfect square lower than n is %d\n",SqrtOfPerfectSquare*SqrtOfPerfectSquare);

        VarHigerThan_n=n;
        while(prime==0)
        {
            prime=1;
            if(VarHigerThan_n<2)
            {
                prime=0;
            }
            else
            {
                if(VarHigerThan_n>2&&VarHigerThan_n%2==0)
                {
                    prime=0;
                }
                else
                {
                    Div=3;
                    while(Div*Div<=VarHigerThan_n)
                    {
                        if(VarHigerThan_n%Div==0)
                        {
                            prime=0;
                        }
                        Div+=2;
                    }

                }
            }
            if(prime==1)
            {
                printf("smallest prime number higher than n is %d",VarHigerThan_n);
            }
            else VarHigerThan_n++;
        }
    }


    return 0;
}
