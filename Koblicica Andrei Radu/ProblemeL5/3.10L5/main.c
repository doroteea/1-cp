#include <stdio.h>
#include <stdlib.h>
int NrOfBanknotes(int ron)
{
    int counter=0;
    while(ron)
    {
        if(ron>=500)
        {
            counter+=ron/500;
            ron%=500;
        }
        if(ron>=200&&ron<500)
        {
            counter+=ron/200;
            ron%=200;
        }
        if(ron>=100&&ron<200)
        {
            counter++;
            ron-=100;
        }
        if(ron>=50&&ron<100)
        {
            counter++;
            ron-=50;
        }
        if(ron>=10&&ron<50)
        {
            counter+=ron/10;
            ron%=10;
        }
        if(ron>=5&&ron<10)
            {
                counter++;
                ron-=5;
            }
        if(ron<5)
        {
            counter+=ron;
            ron=0;
        }
    }
    return counter;

}
int main()
{
    int ron;
    scanf("%d",&ron);
    printf("%d",NrOfBanknotes(ron));
    return 0;
}
