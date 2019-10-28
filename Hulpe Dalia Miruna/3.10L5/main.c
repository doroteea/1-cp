#include <stdio.h>
#include <stdlib.h>
int banknotes(int Money)
{
    int values[7]= {500,200,100,50,10,5,1},NumberOfBanknotes=0,i;
    for(i=0; i<7; i++)
    {
        while(Money>=values[i])
        {
            NumberOfBanknotes++;
            Money=Money-values[i];
        }
    }
    return NumberOfBanknotes;

}
int main()
{
    int Money,NumberOfBanknotes;
    scanf("%d",&Money);
    NumberOfBanknotes=banknotes(Money);
    printf("%d",NumberOfBanknotes);

    return 0;
}
