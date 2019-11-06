#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100];
    int nr,n,i;
    printf("introduce the number: ");
    scanf("%s",&a);
    n=strlen(a);
    printf("%s",a);
    nr=0;
    for(i=0; i<n; i++)
    {
        if(a[i]=='I')
            nr++;
        sum(&nr,'V','I',a,3,5,i);
        else if(a[i]=='V')
        {
            if(a[i-1]=='I')
                nr=nr+3;
            else
                nr=nr+5;
        }
        else if(a[i]=='X')
        {
            if(a[i-1]=='I')
                nr=nr+8;
            else nr=nr+10;
        }
        else if(a[i]=='L')
        {
            if(a[i-1]=='X')
                nr=nr+30;
            else nr=nr+50;
        }
        else if(a[i]=='C')
        {
            if(a[i-1]=='X')
                nr=nr+90;
            else nr=nr+100;
        }
        else if(a[i]=='D')
        {
            if(a[i-1]=='C')
                nr=nr+400;
            else nr=nr+500;
        }
        else if(a[i]=='M')
        {
            if(a[i-1]=='C')
                nr=nr+900;
            else nr=nr+1000;
        }
    }
    printf("\n%d",nr);
    return 0;
}
