#include <stdio.h>
#include <stdlib.h>
int count_banknotes(int amount)
{
    int arr[7]= {500,200,100,50,10,5,1};
    int i;
    int c=0;
    int NrBank=0;
    for(i=0; i<7; i++)
    {
        while(amount>=arr[i])
        {
            c++;
            amount=amount-arr[i];
        }
        NrBank=NrBank+c;
        c=0;
    }
    return NrBank;
}
int main()
{
    int amount;
    scanf("%d",&amount);
    printf("The minimum number of banknotes for paying %d RON is %d",amount,count_banknotes(amount));
    return 0;
}
