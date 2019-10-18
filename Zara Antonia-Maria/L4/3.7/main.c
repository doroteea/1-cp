///hexadecimal number to decimal
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nr[1001];
    int length, decNr=0, power=1,i;
    scanf("%s",nr);
    length=strlen(nr);
    for(i=length-1;i>=0;i--)
    {
        if(nr[i]=='0')decNr=decNr+0*power;
        if(nr[i]=='1')decNr=decNr+1*power;
        if(nr[i]=='2')decNr=decNr+2*power;
        if(nr[i]=='3')decNr=decNr+3*power;
        if(nr[i]=='4')decNr=decNr+4*power;
        if(nr[i]=='5')decNr=decNr+5*power;
        if(nr[i]=='6')decNr=decNr+6*power;
        if(nr[i]=='7')decNr=decNr+7*power;
        if(nr[i]=='8')decNr=decNr+8*power;
        if(nr[i]=='9')decNr=decNr+9*power;
        if(nr[i]=='A')decNr=decNr+10*power;
        if(nr[i]=='B')decNr=decNr+11*power;
        if(nr[i]=='C')decNr=decNr+12*power;
        if(nr[i]=='D')decNr=decNr+13*power;
        if(nr[i]=='E')decNr=decNr+14*power;
        if(nr[i]=='F')decNr=decNr+15*power;
        power=power*16;
    }
    printf("%d",decNr);
    return 0;
}
