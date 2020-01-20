#include <stdio.h>
#include <stdlib.h>
int nr;
int PwrAndDiv(int nr,int *div)
{
    int pwr =0;
     *div=1;
    while(nr/(*div)>9)
    {
        pwr++;
        *div=*div*10;
    }
    return pwr;

}
void Roman(int nr)
{
    int div;
    char *table[4][10]=
    {
        {
            "","I","II","III","IV","V","VI","VII","VIII","IX"
        },
        {
            "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"
        },
        {
            "","C","CC","CCC","CD","D","DC","DCC","DCCC","XM"
        },
        {
            "","M","MM","MMM"
        },
    };
    int pwr=PwrAndDiv(nr,&div);

    while (pwr>=0)
    {
        printf("%s",table[pwr][nr/div]);
        nr=nr%div;
        div=div/10;
        pwr--;
    }
}
int main()
{
    scanf("%d",&nr);
    Roman(nr);
    return 0;
}
