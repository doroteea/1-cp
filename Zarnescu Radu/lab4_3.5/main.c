#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Hello world!\n");
    int n,divis;
    float x;
    scanf("%d",&n);
    x=n;
    while(x>=1)
    {
        if(sqrt(x)*sqrt(x)==x)
        {
            printf("greatest perfect square is:%f",x);
            break;
        }
        x--;
    }
    int leastPrime=n+1;
    while(leastPrime>n)
    {
        int prime=1;
        int divis=2;
        while(pow(divis,2)<=leastPrime)
        {
            if(leastPrime%divis==0)
            {
                prime=0;
                break;
            }
            divis++;
        }
        if(prime==1)
        {
            printf("\nleast prime nr is:%d",leastPrime);
            break;
        }

    }



    return 0;
}
