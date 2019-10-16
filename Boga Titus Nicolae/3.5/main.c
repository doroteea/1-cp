#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int n)
{
    if(!(n%2))
        return 0;
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(!(n%i))
            return 0;

    }
    return 1;

}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",(int)sqrt(n)*(int)sqrt(n));
    for(int i=n;;++i)
        if(IsPrime(i))
        {
            printf("%d",i);
            return 0;
        }//3.13 1.12
    return 0;
}
