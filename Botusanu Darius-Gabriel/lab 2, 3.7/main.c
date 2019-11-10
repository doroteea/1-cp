#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    int i;
    /*This program is supposed to change the lowercase characters from a string to uppercase*/
    printf("Please write your line and press ENTER: ");
    gets(s);

    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s[i]=s[i]-32;
        }
    }
    printf("Here is your line with the lowercase characters turned intro uppercase: %s", s);
    return 0;
}
