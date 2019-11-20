#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    int i,x=0,pwr=1;
    gets(s);
    for(i=strlen(s)-1; i>=0; i--)
    {
        if(s[i]>='1' && s[i]<='9')
        {
            x = x + (s[i]-'0')*pwr;
            pwr = pwr*16;
        }
        else
        {
            x = x + (s[i]-'A'+10)*pwr;
            pwr = pwr*16;

        }
    }
    printf("%d",x);
    return 0;
}
