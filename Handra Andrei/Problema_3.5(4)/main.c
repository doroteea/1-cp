#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int PrimeNumber(int numar)
{
    int divizor;
    if(numar<=1)
        return 0;
    if(numar % 2 == 0 && numar !=2)
        return 0;
    for(divizor=3;divizor*divizor <= numar;divizor=divizor+2)
    {
        if(numar%divizor == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int number,i,verificare;
    float radacina;
    scanf("%d",&number);
    verificare=1;
    for(i=number;i>=1 && verificare==1;i--)
    {
        radacina= sqrt(i);
        if(radacina * radacina == i)
        {
            verificare=0;
            printf("The greatest perfect square is %d\n",i);
        }
    }
    verificare = 1;
    while(verificare == 1)
    {
        if(PrimeNumber(number)==1)
        {
            printf("The prime number is %d",number);
            verificare =0;
        }
        number++;
    }

    return 0;
}
