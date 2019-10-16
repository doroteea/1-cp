#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*3.4. Write a program to generate
all the prime numbers less than or equal to a natural number, n
*/
int TestPrimeNumber(int nr)
{if(nr==1)
{return 0;}
else
   {for(int d=2;d<=sqrt(nr);d++)
        if(nr%d==0)
        return 0;}
    return 1;
}
int main()
{
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++)
    if(TestPrimeNumber(i)==1)
    printf("%d ",i);
    return 0;
}
