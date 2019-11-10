#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    int i;
    fgets(s,sizeof(s),stdin);
    for(i=0; i<(strlen(s)-1); i++)
    {
        s[i]+=32;
        printf("%c",s[i]);
    }
    return 0;
}
