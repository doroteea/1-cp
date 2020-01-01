#include <stdio.h>
#include <stdlib.h>

int main()
{
    char words[69][40];
    int i;
    printf("Please enter the text:\n");
    for(i=0;i<69;i++)
    {
        scanf("%s",words[i]);
    }
    printf("Your text now is:\n");
    for(i=67;i>=0;i--)
    {
        printf("%s ",words[i]);
    }
}
