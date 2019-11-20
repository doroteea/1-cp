#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nr;
    char a[100];
    printf("introduce number:");
    scanf("%d",&nr);
    while(nr>0)
    {
        if(nr>=1000)
        {
            printf("M");
            nr=nr-1000;
        }
        else if(nr>=900)
        {
            printf("CM");
            nr=nr-900;
        }
        else if(nr>=500)
        {
            printf("D");
            nr=nr-500;
        }
        else if(nr>=400)
        {
            printf("CL");
            nr=nr-400;
        }
        else if(nr>=100)
        {
            printf("C");
            nr=nr-100;
        }
        else if(nr>=90)
        {
            printf("XC");
            nr=nr-90;
        }
        else if(nr>=50)
        {
            printf("L");
            nr=nr-50;
        }
        else if(nr>=40)
        {
            printf("XL");
            nr=nr-40;
        }
        else if(nr>=10)
        {
            printf("X");
            nr=nr-10;
        }
        else if(nr==9)
        {
            printf("IX");
            nr=nr-9;
        }
        else if(nr>=5)
        {
            printf("V");
            nr=nr-5;
        }
        else if(nr==4)
        {
            printf("IV");
            nr=nr-4;
        }
        else
        {
            printf("I");
            nr=nr-1;
        }
    }
    return 0;
}
