#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int PrimeNumber(int number)
{
    int divizor;
    if(number<2)
    {
        return 0;
    }
    if(number % 2 == 0 && number !=2)
    {
       return 0;
    }
    for(divizor=3;divizor*divizor <= number;divizor=divizor+2)
    {
        if(number%divizor == 0)
        {
            return 0;
        }
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
