#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int RomanToArabic(char *sir)
{
    int integer=0,i;
    for(i=0; i<strlen(sir); i++)
    {
        switch(sir[i])
        {
        case 'M':
            integer+=1000;
            break;
        case 'D':
            integer+=500;
            break;
        case 'C':
            if(i<strlen(sir)-1&&(sir[i+1]=='M'||sir[i+1]=='D'))
            {
                integer-=100;
            }
            else
            {
                integer+=100;
            }
            break;
        case 'L':
            integer+=50;
            break;
        case 'X':
            if(i<strlen(sir)-1&&(sir[i+1]=='L'||sir[i+1]=='C'))
            {
                integer-=10;
            }
            else
            {
                integer+=10;
            }
            break;
        case 'V':
            integer+=5;
            break;
        case 'I':
            if(i<strlen(sir)-1&&(sir[i+1]=='V'||sir[i+1]=='X'))
            {
                integer-=1;
            }
            else
            {
                integer+=1;
            }
            break;
        }

    }
    return integer;
}

int main()
{
    int n=15;
    char *sir=(char*)malloc(sizeof(char)*n);
    scanf("%s",sir);
    printf("%d",RomanToArabic(sir));
    return 0;
}
