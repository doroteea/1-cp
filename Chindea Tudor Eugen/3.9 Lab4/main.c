#include <stdio.h>
#include <stdlib.h>
int calculatePowerandDivizor(int number,int *divizor){
    int power=0;
    *divizor=1;
    while(number/ (*divizor)>9)
    {
        ++power;
        *divizor=*divizor*10;
    }
    return power;
}
void printRoman(int number)
{
    int divizor;
    char *table[4][10]={
    {"","I","II","III","IV","V","VI","VII","VIII","IX"},
    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"","C","CC","CCC","CD","D","DD","DDD","CM"},
    {"","M","MM","MMM"}
    };
    int power=calculatePowerandDivizor(number,&divizor);
    while(power>=0)
    {
        printf("%s",table[power][number/divizor]);
        number=number%divizor;
        divizor/=10;
        --power;
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    printRoman(number);
    return 0;
}
